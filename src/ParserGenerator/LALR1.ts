import Grammar from '../Grammar';
import {
  ENonTerminal,
  GrammarSymbol,
  Terminal,
} from '../Grammar/GrammarSymbol';
import Production from '../Grammar/Production';
import State from '../Grammar/State';
import StateItem from '../Grammar/StateItem';
import GrammarUtils from '../Grammar/Utils';
import { ETokenType, opPrecedence } from '../Lexer/TokenType';
import Utils from './Utils';
import {
  ActionInfo,
  ActionTable,
  EAction,
  GotoTable,
  StateActionTable,
  StateGotoTable,
} from './common';

export default class LALR1 {
  readonly firstSetMap: Map<ENonTerminal, Set<Terminal>> = new Map();
  readonly followSetMap: Map<ENonTerminal, Set<Terminal>> = new Map();

  readonly actionTable: StateActionTable = new Map();
  readonly gotoTable: StateGotoTable = new Map();
  private grammar: Grammar;

  /** For circle detect */
  private _firstSetNTStack: ENonTerminal[] = [];

  constructor(grammar: Grammar) {
    this.grammar = grammar;
  }

  generate() {
    this.computeFirstSet();
    this.buildStateTable();
  }

  private buildStateTable() {
    const startStateItemCore = [
      new StateItem(this.grammar.productions[0], 0, [ETokenType.EOF]),
    ];
    const startState = State.create(startStateItemCore);
    this._extendState(startState);
  }

  private _extendState(state: State) {
    if (!state.dirtyLookahead) return;
    this.closure(state);
    const newStates = this.inferNextState(state);
    for (const ns of newStates) {
      this._extendState(ns);
    }
  }

  private closure(state: State) {
    for (const core of state.cores) {
      if (!core.canReduce()) {
        this._extendStateItem(state, core);
      }
    }
    state.closured = true;
    return state;
  }

  private _extendStateItem(state: State, item: StateItem) {
    if (GrammarUtils.isTerminal(item.curSymbol)) return;

    const productionList = this.grammar.getProductionList(
      <ENonTerminal>item.curSymbol
    );

    if (item.nextSymbol) {
      let newLookaheadSet = new Set<Terminal>();
      let lastFirstSet: Set<Terminal> | undefined;
      let terminalExist = false;
      // when A :=> a.BC, a;  ==》 B :=> .xy, First(Ca)
      // newLookAhead = First(Ca)
      for (
        let i = 1, nextSymbol = item.symbolByOffset(1);
        !!nextSymbol;
        nextSymbol = item.symbolByOffset(++i)
      ) {
        if (GrammarUtils.isTerminal(nextSymbol)) {
          newLookaheadSet.add(<Terminal>nextSymbol);
          terminalExist = true;
          break;
        }
        lastFirstSet = this.firstSetMap.get(<ENonTerminal>nextSymbol)!;
        for (const t of lastFirstSet) {
          newLookaheadSet.add(t);
        }
        if (!lastFirstSet.has(ETokenType.EPSILON)) break;
      }
      if (!terminalExist && lastFirstSet?.has(ETokenType.EPSILON)) {
        for (const t of item.lookaheadSet) {
          newLookaheadSet.add(t);
        }
      }

      for (const production of productionList) {
        const newItem = state.createStateItem(production, 0);
        if (
          !state.items.has(newItem) ||
          !Utils.isSubSet(newLookaheadSet, newItem.lookaheadSet)
        ) {
          state.items.add(newItem);
          newItem.addLookahead(newLookaheadSet);
          this._extendStateItem(state, newItem);
        }
      }
    } else {
      for (const production of productionList) {
        const newItem = state.createStateItem(production, 0);
        if (
          !state.items.has(newItem) ||
          !Utils.isSubSet(item.lookaheadSet, newItem.lookaheadSet)
        ) {
          state.items.add(newItem);
          newItem.addLookahead(item.lookaheadSet);
          this._extendStateItem(state, newItem);
        }
      }
    }
  }

  private inferNextState(state: State): Set<State> {
    const coreMap: Map<GrammarSymbol, Set<StateItem>> = new Map();
    const stateActionTable: ActionTable =
      this.actionTable.get(state.id) ?? new Map();
    const stateGotoTable: GotoTable = this.gotoTable.get(state.id) ?? new Map();

    this.actionTable.set(state.id, stateActionTable);
    this.gotoTable.set(state.id, stateGotoTable);

    for (const stateItem of state.items) {
      if (stateItem.canReduce()) {
        let action: ActionInfo;
        if (stateItem.production.goal !== ENonTerminal.START) {
          action = {
            action: EAction.Reduce,
            target: stateItem.production.id,
          };
        } else {
          action = { action: EAction.Accept };
        }

        for (const t of stateItem.lookaheadSet) {
          stateActionTable.set(t, action);
        }
      } else {
        const nextItem = stateItem.advance();
        Utils.addMapSetItem(coreMap, stateItem.curSymbol, nextItem);
      }

      stateItem.dirtyLookahead = false;
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

    return newStates;
  }

  /** Resolve shift-reduce conflict by operator precedence */
  // private addAction(
  //   table: ActionTable,
  //   terminal: Terminal,
  //   action: ActionInfo,
  //   reduceProduction: Production
  // ) {
  //   const exist = table.get(terminal);
  //   if (!exist) table.set(terminal, action);
  //   else if (exist.action !== action.action) {
  //     let shiftAction: ActionInfo, reduceAction: ActionInfo;
  //     if (exist.action === EAction.Reduce) {
  //       shiftAction = action;
  //       reduceAction = exist;
  //     } else {
  //       shiftAction = exist;
  //       reduceAction = action;
  //     }

  //     const shiftPrecedence = opPrecedence.get(<ETokenType>terminal);
  //     if (shiftPrecedence == undefined) {
  //       throw `No precedence defined on operator ${GrammarUtils.toString(
  //         terminal
  //       )}`;
  //     }
  //     const reducePrecedence = reduceProduction.getReducePrecedence();
  //     if (reducePrecedence == undefined) {
  //       throw `No precedence defined on production ${reduceProduction.toString()}`;
  //     }

  //     // TODO: take association into account
  //     const newAction =
  //       shiftPrecedence <= reducePrecedence ? shiftAction : reduceAction;
  //     table.set(terminal, newAction);
  //   } else {
  //     throw 'Action conflict occur!';
  //   }
  // }

  // https://people.cs.pitt.edu/~jmisurda/teaching/cs1622/handouts/cs1622-first_and_follow.pdf
  private computeFirstSet() {
    for (const production of this.grammar.productions.slice(1)) {
      this.computeFirstSetForNT(production.goal);
    }
  }

  // private computeFollowSet() {
  //   // Step 1
  //   this.followSetMap.set(this.grammar.startSymbol, new Set([ETokenType.EOF]));

  //   // Step 2
  //   for (const production of this.grammar.productions.slice(1)) {
  //     this.computeFollowSetBaseOnFirstSet(production.derivation);
  //   }

  //   // Step 3
  //   for (const production of this.grammar.productions.slice(1)) {
  //     this.computeFollowSetBaseOnFollowSet(production);
  //   }
  // }

  // private computeFollowSetBaseOnFirstSet(derivation: Derivation) {
  //   for (let i = 0; i < derivation.length - 1; i++) {
  //     const gs = derivation[i];
  //     if (GrammarUtils.isTerminal(gs)) continue;

  //     const nextItem = derivation[i + 1];
  //     if (GrammarUtils.isTerminal(nextItem)) {
  //       this._addFollowItem(<ENonTerminal>gs, <Terminal>nextItem);
  //     } else {
  //       const firstSet = this.firstSetMap.get(<ENonTerminal>nextItem)!;
  //       this._addFollowItem(<ENonTerminal>gs, firstSet);
  //     }
  //   }
  // }

  // private computeFollowSetBaseOnFollowSet(production: Production) {
  //   const { goal, derivation } = production;
  //   const followSet = this.followSetMap.get(<ENonTerminal>goal) ?? new Set();

  //   for (let i = derivation.length - 1; i >= 0; i--) {
  //     const lastSymbol = derivation[i];
  //     if (
  //       GrammarUtils.isTerminal(lastSymbol) &&
  //       lastSymbol !== ETokenType.EPSILON
  //     )
  //       return;

  //     if (lastSymbol !== ETokenType.EPSILON)
  //       this._addFollowItem(<ENonTerminal>lastSymbol, followSet);

  //     if (
  //       lastSymbol === ETokenType.EPSILON ||
  //       this.firstSetMap.get(<ENonTerminal>lastSymbol)?.has(ETokenType.EPSILON)
  //     ) {
  //       const preLastSymbol = derivation[i - 1];
  //       if (preLastSymbol && !GrammarUtils.isTerminal(preLastSymbol)) {
  //         this._addFollowItem(<ENonTerminal>preLastSymbol, followSet);
  //       } else break;
  //     } else break;
  //   }
  // }

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

  // private _addFollowItem(
  //   nonTerminal: ENonTerminal,
  //   set: Set<Terminal> | Terminal
  // ) {
  //   const followSet = this.followSetMap.get(nonTerminal) ?? new Set<Terminal>();

  //   if (set instanceof Set) {
  //     for (const sm of set.values()) {
  //       if (sm !== ETokenType.EPSILON) followSet.add(sm);
  //     }
  //   } else {
  //     followSet.add(set);
  //   }

  //   this.followSetMap.set(nonTerminal, followSet);
  // }
}
