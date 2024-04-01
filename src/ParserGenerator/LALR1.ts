import { writeFileSync } from 'fs';
import Grammar from '../Grammar';
import {
  Derivation,
  ENonTerminal,
  GrammarSymbol,
  Terminal,
} from '../Grammar/GrammarSymbol';
import Production from '../Grammar/Production';
import State from '../Grammar/State';
import StateItem from '../Grammar/StateItem';
import GrammarUtils from '../Grammar/Utils';
import { ETokenType } from '../Lexer/TokenType';
import Utils from './Utils';

type StateActionTable = Map<number /** state ID */, ActionTable>;
type ActionTable = Map<Terminal, ActionInfo>;
type StateGotoTable = Map<number /** state ID */, GotoTable>;
type GotoTable = Map<ENonTerminal, number /** state ID */>;

enum EAction {
  Shift = 0,
  Reduce,
  Accept,
}

interface ActionInfo {
  action: EAction;
  target?: number;
}

export default class LALR1 {
  private readonly firstSetMap: Map<ENonTerminal, Set<Terminal>> = new Map();
  private readonly followSetMap: Map<ENonTerminal, Set<Terminal>> = new Map();

  private readonly actionTable: StateActionTable = new Map();
  private readonly gotoTable: StateGotoTable = new Map();
  private grammar: Grammar;

  /** For circle detect */
  private _firstSetNTStack: ENonTerminal[] = [];

  constructor(grammar: Grammar) {
    this.grammar = grammar;
  }

  generate() {
    this.computeFirstSet();
    // TEST:
    this.printFirstSet();
    // this.computeFollowSet();
    // // TEST:
    // this.printFollowSet();
    this.buildStateTable();
  }

  /**
   * actiontable\n
   * stateid:TERMINAL|ACTION{Sstateid/R/A};*\n*
   * gototable\n
   * stateid:NONTERMINAL|stateid;*\n*
   */
  serialize() {
    let encodedStr = 'ActionTable\n';
    for (const [stateId, AT] of this.actionTable) {
      encodedStr += `${stateId}:`;
      for (const [terminal, action] of AT) {
        encodedStr += `${terminal}|${this.serializeAction(action)};`;
      }
      encodedStr += '\n';
    }

    encodedStr += 'GOTOTable\n';
    for (const [stateId, GT] of this.gotoTable) {
      encodedStr += `${stateId}:`;
      for (const [NT, stateId] of GT) {
        encodedStr += `${NT}|${stateId};`;
      }
      encodedStr += '\n';
    }
    const binaryBuf = new ArrayBuffer(encodedStr.length);
    const dataView = new DataView(binaryBuf);
    for (let i = 0; i < encodedStr.length; i++) {
      dataView.setUint8(i, encodedStr.charCodeAt(i));
    }
    writeFileSync('lalr1.bin', dataView);

    console.log(encodedStr);
  }

  serializeAction(action: ActionInfo) {
    switch (action.action) {
      case EAction.Accept:
        return 'A';
      case EAction.Reduce:
        return 'R';
      case EAction.Shift:
        return `S${action.target!}`;
    }
  }

  deserializeAction(str: string): ActionInfo {
    switch (str) {
      case 'A':
        return { action: EAction.Accept };
      case 'R':
        return { action: EAction.Reduce };
      default:
        return { action: EAction.Shift, target: Number(str.slice(1)) };
    }
  }

  private buildStateTable() {
    const startStateItemCore = [
      new StateItem(this.grammar.productions[0], 0, [ETokenType.EOF]),
    ];
    const startState = State.create(startStateItemCore);
    this._extendState(startState);
  }

  private _extendState(state: State) {
    if (state.closured) return;
    this.closure(state);
    const newStates = this.inferNextState(state);
    for (const ns of newStates) {
      this._extendState(ns);
    }
  }

  private closure(state: State) {
    if (state.closured) return;
    for (const core of state.cores) {
      if (!core.canReduce()) {
        this._extendStateItem(state, core);
      }
    }
    state.closured = true;
    return state;
  }

  private inferNextState(state: State): Set<State> {
    const coreMap: Map<GrammarSymbol, Set<StateItem>> = new Map();
    const stateActionTable: ActionTable =
      this.actionTable.get(state.id) ?? new Map();
    const stateGotoTable: GotoTable = this.gotoTable.get(state.id) ?? new Map();

    for (const stateItem of state.items) {
      if (stateItem.canReduce()) {
        const action =
          stateItem.production.goal === ENonTerminal.START
            ? EAction.Accept
            : EAction.Reduce;
        for (const t of stateItem.lookaheadSet) {
          stateActionTable.set(<Terminal>t, { action });
        }
      } else {
        const nextItem = stateItem.advance();
        Utils.addMapSetItem(coreMap, stateItem.curSymbol, nextItem);
      }
    }

    const newStates = new Set<State>();
    for (const [gs, cores] of coreMap.entries()) {
      const newState = State.create(Array.from(cores));
      if (GrammarUtils.isTerminal(gs)) {
        stateActionTable.set(<Terminal>gs, {
          action: EAction.Shift,
          target: newState.id,
        });
      } else {
        stateGotoTable.set(<ENonTerminal>gs, newState.id);
      }

      newStates.add(newState);
    }
    this.actionTable.set(state.id, stateActionTable);
    this.gotoTable.set(state.id, stateGotoTable);
    return newStates;
  }

  // https://people.cs.pitt.edu/~jmisurda/teaching/cs1622/handouts/cs1622-first_and_follow.pdf
  private computeFirstSet() {
    for (const production of this.grammar.productions.slice(1)) {
      this.computeFirstSetForNT(production.goal);
    }
  }

  private computeFollowSet() {
    // Step 1
    this.followSetMap.set(this.grammar.startSymbol, new Set([ETokenType.EOF]));

    // Step 2
    for (const production of this.grammar.productions.slice(1)) {
      this.computeFollowSetBaseOnFirstSet(production.derivation);
    }

    // Step 3
    for (const production of this.grammar.productions.slice(1)) {
      this.computeFollowSetBaseOnFollowSet(production);
    }
  }

  private computeFollowSetBaseOnFirstSet(derivation: Derivation) {
    for (let i = 0; i < derivation.length - 1; i++) {
      const gs = derivation[i];
      if (GrammarUtils.isTerminal(gs)) continue;

      const nextItem = derivation[i + 1];
      if (GrammarUtils.isTerminal(nextItem)) {
        this._addFollowItem(<ENonTerminal>gs, <Terminal>nextItem);
      } else {
        const firstSet = this.firstSetMap.get(<ENonTerminal>nextItem)!;
        this._addFollowItem(<ENonTerminal>gs, firstSet);
      }
    }
  }

  private computeFollowSetBaseOnFollowSet(production: Production) {
    const { goal, derivation } = production;
    const followSet = this.followSetMap.get(<ENonTerminal>goal) ?? new Set();

    for (let i = derivation.length - 1; i >= 0; i--) {
      const lastSymbol = derivation[i];
      if (
        GrammarUtils.isTerminal(lastSymbol) &&
        lastSymbol !== ETokenType.EPSILON
      )
        return;

      if (lastSymbol !== ETokenType.EPSILON)
        this._addFollowItem(<ENonTerminal>lastSymbol, followSet);

      if (
        lastSymbol === ETokenType.EPSILON ||
        this.firstSetMap.get(<ENonTerminal>lastSymbol)?.has(ETokenType.EPSILON)
      ) {
        const preLastSymbol = derivation[i - 1];
        if (preLastSymbol && !GrammarUtils.isTerminal(preLastSymbol)) {
          this._addFollowItem(<ENonTerminal>preLastSymbol, followSet);
        } else break;
      } else break;
    }
  }

  private computeFirstSetForNT(NT: ENonTerminal) {
    // circle detect
    const idx = this._firstSetNTStack.findIndex((item) => item === NT);
    if (idx !== -1) {
      const computingFS = this.firstSetMap.get(NT)!;
      const len = this._firstSetNTStack.length;
      for (let i = len - 1; i > idx; i--) {
        const curNT = this._firstSetNTStack[i];
        this.firstSetMap.set(curNT, computingFS);
      }
      return computingFS;
    }
    this._firstSetNTStack.push(NT);

    const productionList = this.grammar.getProductionList(NT);
    const firstSet = new Set<Terminal>();
    this.firstSetMap.set(NT, firstSet);
    if (this.grammar.isNullableNT(NT)) firstSet.add(ETokenType.EPSILON);

    for (const production of productionList) {
      let i = 0;
      for (; i < production.derivation.length; i++) {
        const gs = production.derivation[i];
        if (GrammarUtils.isTerminal(gs)) {
          firstSet.add(<Terminal>gs);
          break;
        }

        const succeedFirstSet = this.computeFirstSetForNT(<ENonTerminal>gs);

        for (const item of succeedFirstSet) {
          if (item !== ETokenType.EPSILON) firstSet.add(item);
        }
        if (!this.grammar.isNullableNT(<ENonTerminal>gs)) break;
      }
      if (i === production.derivation.length) firstSet.add(ETokenType.EPSILON);
    }

    this._firstSetNTStack.pop();
    return firstSet;
  }

  private _addFollowItem(
    nonTerminal: ENonTerminal,
    set: Set<Terminal> | Terminal
  ) {
    const followSet = this.followSetMap.get(nonTerminal) ?? new Set<Terminal>();

    if (set instanceof Set) {
      for (const sm of set.values()) {
        if (sm !== ETokenType.EPSILON) followSet.add(sm);
      }
    } else {
      followSet.add(set);
    }

    this.followSetMap.set(nonTerminal, followSet);
  }

  private _extendStateItem(state: State, item: StateItem) {
    if (GrammarUtils.isTerminal(item.curSymbol)) {
      return;
    }

    const productionList = this.grammar.getProductionList(
      <ENonTerminal>item.curSymbol
    );

    if (item.nextSymbol) {
      let newLookaheadSet = new Set<Terminal>();
      let lastFirstSet: Set<Terminal> | undefined;
      // when A :=> a.BC, a;  ==》 B :=> .xy, First(Ca)
      // newLookAhead = First(Ca)
      for (
        let i = 1, nextSymbol = item.symbolByOffset(1);
        !!nextSymbol;
        nextSymbol = item.symbolByOffset(++i)
      ) {
        if (GrammarUtils.isTerminal(nextSymbol)) {
          newLookaheadSet.add(<Terminal>nextSymbol);
          break;
        }
        lastFirstSet = this.firstSetMap.get(<ENonTerminal>nextSymbol)!;
        for (const t of lastFirstSet) {
          newLookaheadSet.add(t);
        }
        if (!lastFirstSet.has(ETokenType.EPSILON)) break;
      }
      if (lastFirstSet?.has(ETokenType.EPSILON)) {
        for (const t of item.lookaheadSet) {
          newLookaheadSet.add(t);
        }
      }

      for (const production of productionList) {
        const newItem = state.createStateItem(production, 0);
        if (!state.items.has(newItem)) {
          state.items.add(newItem);
          this._extendStateItem(state, newItem);
          newItem.addLookahead(newLookaheadSet);
        }
      }
    } else {
      for (const production of productionList) {
        const newItem = state.createStateItem(production, 0);
        if (!state.items.has(newItem)) {
          state.items.add(newItem);
          this._extendStateItem(state, newItem);
          newItem.addLookahead(item.lookaheadSet);
        }
      }
    }
  }

  // TEST: for debug
  printFirstSet() {
    console.log('========== First Set ==========');
    for (const [NT, set] of this.firstSetMap.entries()) {
      console.log(
        `${`First(${ENonTerminal[NT]})`.padEnd(15)} -> ${[...set.values()]
          .map((item) => GrammarUtils.toString(item))
          .join(', ')}`
      );
    }
  }

  printFollowSet() {
    console.log('========== Follow Set ==========');
    for (const [NT, set] of this.followSetMap.entries()) {
      console.log(
        `${`Follow(${ENonTerminal[NT]})`.padEnd(15)} -> ${[...set.values()]
          .map((item) => GrammarUtils.toString(item))
          .join(', ')}`
      );
    }
  }

  printParsingTable(info: {
    terminalSymbols: Terminal[];
    nonTerminalSymbols: ENonTerminal[];
  }) {
    console.log('========== Parsing Table ==========');
    let tmp = '';
    for (const state of State.pool.values()) {
      tmp += `${state.id}: \n`.padEnd(4);
      for (const psItem of state.items) {
        tmp += '     ' + psItem.toString() + '\n';
      }
    }
    console.log(tmp);

    const terminalSymbols = info?.terminalSymbols;
    const nonTerminalSymbols = info?.nonTerminalSymbols;

    const unitPadding = 10;

    let str = '';
    const printCell = (text: string | number, unit: number) => {
      str += `| ${text}`.padEnd(unit * unitPadding);
    };
    let lineLength = 0;
    const printLineBreak = () => {
      str += '|\n|';
      for (let i = 1; i < lineLength - 1; i++) {
        str += '-';
      }
      str += '|\n';
    };

    printCell('State', 1);
    printCell('Action', terminalSymbols.length);
    printCell('GOTO', nonTerminalSymbols.length);
    lineLength = str.length + 1;
    printLineBreak();
    printCell('', 1);
    for (const sm of terminalSymbols) {
      printCell(GrammarUtils.toString(sm), 1);
    }
    for (const sm of nonTerminalSymbols) {
      printCell(ENonTerminal[sm], 1);
    }
    printLineBreak();

    for (const state of State.pool.values()) {
      printCell(state.id, 1);
      const actionTable = this.actionTable.get(state.id)!;
      for (const terminal of terminalSymbols) {
        const action = actionTable.get(terminal);
        if (!action) printCell('', 1);
        else {
          if (action.action === EAction.Accept) {
            printCell('AC', 1);
          } else if (action.action === EAction.Reduce) {
            printCell('RD', 1);
          } else {
            printCell(`S${action.target}`, 1);
          }
        }
      }

      const gotoTable = this.gotoTable.get(state.id)!;
      for (const nonTerminal of nonTerminalSymbols) {
        const state = gotoTable.get(nonTerminal);
        printCell(state ?? '', 1);
      }
      printLineBreak();
    }
    console.log(str);
  }
}
