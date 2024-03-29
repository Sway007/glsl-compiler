/** LR1 Parser */

import Grammar from './Grammar';
import ParsingState, {
  ActionInfo,
  EParsingAction,
  ParsingStateItem,
} from './ParsingState';
import GSymbol, { Derivation, eof } from './Symbol';
import ParserUtils from './Utils';

type StateActionTable = Map<number /** state ID */, ActionTable>;
type ActionTable = Map<GSymbol, ActionInfo[]>;
type StateGotoTable = Map<number /** state ID */, GotoTable>;
type GotoTable = Map<GSymbol, number /** state ID */>;

export default class LR1Parser {
  private readonly firstSetMap: Map<GSymbol, Set<GSymbol>> = new Map();
  private readonly followSetMap: Map<GSymbol, Set<GSymbol>> = new Map();

  private readonly actionTable: StateActionTable = new Map();
  private readonly gotoTable: StateGotoTable = new Map();

  private static readonly initialSymbol = GSymbol.create('#S`', true);

  computeFirstAndFollowSet(grammar: Grammar) {
    for (const nt of grammar.nonTerminals) {
      this._computeFirstForGS(nt, grammar);
    }
    this._computeFollowSet(grammar);
  }

  buildParsingTable(grammar: Grammar) {
    // step1
    const derivation = [grammar.startGSymbol];
    const initialProduction = grammar.addProduction(
      LR1Parser.initialSymbol,
      derivation
    );

    // step2
    const initialParsingItem = ParsingStateItem.getItem(initialProduction, 0);
    const initialParsingState = ParsingState.createClosureState(
      [initialParsingItem],
      grammar
    );

    // step3
    this._inferParsingState(initialParsingState, grammar);
  }

  printFirstSet() {
    console.log('========== First Set ==========');
    for (const [nonTerminal, set] of this.firstSetMap.entries()) {
      console.log(
        `${`First(${nonTerminal.text.toString()})`.padEnd(15)} -> ${[
          ...set.values(),
        ]
          .map((item) => item.text)
          .join(', ')}`
      );
    }
  }

  printFollowSet() {
    console.log('========== Follow Set ==========');
    for (const [nonTerminal, set] of this.followSetMap.entries()) {
      console.log(
        `${`Follow(${nonTerminal.text.toString()})`.padEnd(15)} -> ${[
          ...set.values(),
        ]
          .map((item) => item.text)
          .join(', ')}`
      );
    }
  }

  printParsingTable(info?: {
    terminalSymbols: GSymbol[];
    nonTerminalSymbols: GSymbol[];
  }) {
    console.log('========== Parsing Table ==========');
    let tmp = '';
    for (const state of ParsingState.pool.values()) {
      tmp += `${state.ID}: \n`.padEnd(4);
      for (const psItemList of state.items.values()) {
        for (const psItem of psItemList) {
          tmp += '     ' + psItem.toString() + '\n';
        }
      }
    }
    console.log(tmp);

    const terminalSymbols = info?.terminalSymbols ?? GSymbol.terminals;
    const nonTerminalSymbols = info?.nonTerminalSymbols ?? GSymbol.nonTerminals;

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
      printCell(sm.text, 1);
    }
    for (const sm of nonTerminalSymbols) {
      printCell(sm.text, 1);
    }
    printLineBreak();

    for (const state of ParsingState.pool.values()) {
      printCell(state.ID, 1);
      const actionTable = this.actionTable.get(state.ID)!;
      for (const terminal of terminalSymbols) {
        const actionList = actionTable.get(terminal);
        if (!actionList?.length) printCell('', 1);
        else {
          const as: string[] = [];
          for (const action of actionList) {
            if (action.action === EParsingAction.Accept) {
              as.push('AC');
            } else if (action.action === EParsingAction.Reduce) {
              as.push('RD');
            } else {
              as.push(`S${action.state}`);
            }
          }
          printCell(as.join(', '), 1);
        }
      }

      const gotoTable = this.gotoTable.get(state.ID)!;
      for (const nonTerminal of nonTerminalSymbols) {
        const state = gotoTable.get(nonTerminal);
        printCell(state ?? '', 1);
      }
      printLineBreak();
    }
    console.log(str);
  }

  private _inferParsingState(state: ParsingState, grammar: Grammar) {
    state.extended = true;
    let actionTable: ActionTable = this.actionTable.get(state.ID) ?? new Map();
    let gotoTable: GotoTable = this.gotoTable.get(state.ID) ?? new Map();
    this.actionTable.set(state.ID, actionTable);
    this.gotoTable.set(state.ID, gotoTable);

    const cores: Map<GSymbol, ParsingStateItem[]> = new Map();

    for (const [gSymbol, psItemList] of state.items.entries()) {
      for (const psItem of psItemList) {
        if (psItem.canReduce) {
          if (gSymbol === LR1Parser.initialSymbol) {
            // accept
            ParserUtils.addMapArrayItem(actionTable, eof, {
              action: EParsingAction.Accept,
            });
          } else {
            // reduce
            const action: ActionInfo = { action: EParsingAction.Reduce };
            const followSet = this.followSetMap.get(
              psItem.curSymbol.nonTerminal ? psItem.curSymbol : gSymbol
            )!;
            if (!followSet) debugger;

            for (const gs of followSet.values()) {
              ParserUtils.addMapArrayItem(actionTable, gs, action);
            }
          }
        } else {
          const nextItem = psItem.advance();
          ParserUtils.addMapArrayItem(cores, psItem.peek, nextItem);
        }
      }
    }

    for (const [gs, items] of cores.entries()) {
      const newState = ParsingState.createClosureState(items, grammar);
      if (gs.nonTerminal) {
        gotoTable.set(gs, newState.ID);
      } else {
        ParserUtils.addMapArrayItem(actionTable, gs, {
          action: EParsingAction.Shift,
          state: newState.ID,
        });
      }
      if (!newState.extended) {
        this._inferParsingState(newState, grammar);
      }
    }
  }

  private _computeFollowSet(grammar: Grammar) {
    // Step 1
    this._addFollowItem(grammar.startGSymbol, eof);
    // Step 2
    for (const productionList of grammar.productions.values()) {
      for (const production of productionList) {
        this._computeFollowSetBasedOnFirst(production.derivation);
      }
    }
    // Step 3
    for (const [nonTerminal, productionList] of grammar.productions.entries()) {
      for (const production of productionList) {
        this._computeFollowSetBasedOnFollow(nonTerminal, production.derivation);
      }
    }
  }

  private _computeFirstForGS(sm: GSymbol, grammar: Grammar): Set<GSymbol> {
    if (!sm.nonTerminal) return new Set([sm]);
    if (this.firstSetMap.has(sm)) return this.firstSetMap.get(sm)!;

    const firstSet: Set<GSymbol> = new Set();
    this.firstSetMap.set(sm, firstSet);
    const productionList = grammar.productions.get(sm)!;
    for (let i = 0; i < productionList.length; i++) {
      for (const sym of productionList[i].derivation) {
        if (!sym.nonTerminal) {
          firstSet.add(sym);
          break;
        }
        const nfs = this._computeFirstForGS(sym, grammar);
        for (const item of nfs) {
          if (item !== eof) firstSet.add(item);
        }
        if (!nfs.has(eof)) break;
      }
    }

    return firstSet;
  }

  /** step 2 */
  private _computeFollowSetBasedOnFirst(derivation: Derivation) {
    for (let i = 0; i < derivation.length - 1; i++) {
      const item = derivation[i];
      if (!item.nonTerminal) continue;
      const followItem = derivation[i + 1];
      if (followItem.nonTerminal) {
        const firstSet = this.firstSetMap.get(followItem)!;
        this._addFollowItem(item, firstSet);
      } else {
        this._addFollowItem(item, followItem);
      }
    }
  }

  /** step 3 */
  private _computeFollowSetBasedOnFollow(
    nonTerminal: GSymbol,
    derivation: Derivation
  ) {
    if (!nonTerminal.nonTerminal)
      throw `Error: ${nonTerminal.text} is terminal`;

    const followSet = this.followSetMap.get(nonTerminal) ?? new Set();
    const lastItem = derivation[derivation.length - 1];
    if (lastItem.nonTerminal) {
      this._addFollowItem(lastItem, followSet);
    }

    const lastSecondItem = derivation[derivation.length - 2];
    if (lastSecondItem && lastSecondItem.nonTerminal) {
      if (lastItem.nonTerminal) {
        const firstSet = this.firstSetMap.get(lastItem)!;
        if (firstSet.has(eof)) {
          this._addFollowItem(lastSecondItem, followSet);
        }
      } else if (lastItem === eof) {
        this._addFollowItem(lastSecondItem, followSet);
      }
    }
  }

  private _addFollowItem(nonTerminal: GSymbol, set: Set<GSymbol> | GSymbol) {
    const followSet = this.followSetMap.get(nonTerminal) ?? new Set<GSymbol>();

    if (set instanceof Set) {
      for (const sm of set.values()) {
        followSet.add(sm);
      }
    } else {
      followSet.add(set);
    }

    this.followSetMap.set(nonTerminal, followSet);
  }
}
