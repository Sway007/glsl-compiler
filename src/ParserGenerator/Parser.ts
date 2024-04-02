import Grammar from '../Grammar';
import {
  ENonTerminal,
  GrammarSymbol,
  Terminal,
} from '../Grammar/GrammarSymbol';
import { ETokenType } from '../Lexer/TokenType';
import { EAction, StateActionTable, StateGotoTable } from './common';

export default class Parser {
  readonly actionTable: StateActionTable;
  readonly gotoTable: StateGotoTable;
  readonly grammar: Grammar;
  private traceBackStack: (GrammarSymbol | number | EAction)[] = [];

  private get curState() {
    return this.traceBackStack[this.traceBackStack.length - 1];
  }
  private get stateActionTable() {
    return this.actionTable.get(this.curState)!;
  }
  private get stateGotoTable() {
    return this.gotoTable.get(this.curState);
  }

  constructor(
    actionTable: StateActionTable,
    gotoTable: StateGotoTable,
    grammar: Grammar
  ) {
    this.actionTable = actionTable;
    this.gotoTable = gotoTable;
    this.grammar = grammar;
  }

  parse(tokens: Array<GrammarSymbol>) {
    const { traceBackStack } = this;
    traceBackStack.push(0);
    tokens.push(ETokenType.EOF);

    for (let idx = 0; idx < tokens.length; ) {
      const token = tokens[idx];
      const actionInfo = this.stateActionTable.get(<Terminal>token);
      if (actionInfo?.action === EAction.Shift) {
        traceBackStack.push(token, actionInfo.target!);
        idx++;
      } else if (actionInfo?.action === EAction.Accept) {
        console.log('Accept!');
        return;
      } else if (actionInfo?.action === EAction.Reduce) {
        const target = actionInfo.target!;
        const reduceProduction = this.grammar.getProductionByID(target)!;
        for (let i = 0; i < reduceProduction.derivation.length; i++) {
          traceBackStack.pop();
          traceBackStack.pop();
        }
        const gotoTable = this.stateGotoTable;
        traceBackStack.push(reduceProduction.goal);
        const nextState = gotoTable?.get(reduceProduction.goal)!;
        traceBackStack.push(nextState);
        continue;
      } else {
        throw 'invalid action table';
      }
    }
    throw 'failed to parse';
  }
}
