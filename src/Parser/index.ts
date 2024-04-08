import Grammar from '../Grammar';
import { ENonTerminal } from '../Grammar/GrammarSymbol';
import GrammarUtils from '../Grammar/Utils';
import Token from '../Lexer/Token';
import { ETokenType } from '../Lexer/TokenType';
import {
  EAction,
  StateActionTable,
  StateGotoTable,
} from '../ParserGenerator/common';
import SematicAnalyzer from './SemanticAnalyzer';

export default class Parser {
  readonly actionTable: StateActionTable;
  readonly gotoTable: StateGotoTable;
  readonly grammar: Grammar;
  readonly sematicAnalyzer: SematicAnalyzer;
  private traceBackStack: (Token | ENonTerminal | number)[] = [];

  private get curState() {
    return this.traceBackStack[this.traceBackStack.length - 1] as ENonTerminal;
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
    this.sematicAnalyzer = new SematicAnalyzer();
  }

  parse(tokens: Generator<Token, Token>) {
    const { traceBackStack, sematicAnalyzer } = this;
    traceBackStack.push(0);

    let nextToken = tokens.next();
    while (true) {
      const token = nextToken.value;
      if (token.type === ETokenType.LEFT_BRACE) {
        sematicAnalyzer.newScope();
      } else if (token.type === ETokenType.RIGHT_BRACE) {
        sematicAnalyzer.dropScope();
      }

      const actionInfo = this.stateActionTable.get(token.type);
      if (actionInfo?.action === EAction.Shift) {
        traceBackStack.push(token, actionInfo.target!);
        nextToken = tokens.next();
        this.printStack(nextToken.value);
      } else if (actionInfo?.action === EAction.Accept) {
        console.log('Accept!');
        sematicAnalyzer.acceptRule?.(sematicAnalyzer);
        return;
      } else if (actionInfo?.action === EAction.Reduce) {
        const target = actionInfo.target!;
        const reduceProduction = this.grammar.getProductionByID(target)!;
        console.log(`Reduce: ${reduceProduction.toString()}`);
        const translationRule = sematicAnalyzer.getTranslationRule(
          reduceProduction.id
        );

        const values: (Token | ENonTerminal)[] = [];

        for (let i = 0; i < reduceProduction.derivation.length; i++) {
          traceBackStack.pop();
          values.unshift(<Token>traceBackStack.pop());
        }
        this.printStack(token);
        translationRule?.(sematicAnalyzer, ...values);

        const gotoTable = this.stateGotoTable;
        traceBackStack.push(reduceProduction.goal);

        const nextState = gotoTable?.get(reduceProduction.goal)!;
        traceBackStack.push(nextState);
        this.printStack(token);
        continue;
      } else {
        throw 'invalid action table';
      }
    }
  }

  // TEST
  printStack(nextToken: Token) {
    let str = '';
    for (let i = 0; i < this.traceBackStack.length - 1; i++) {
      const state = <ENonTerminal>this.traceBackStack[i++];
      const token = this.traceBackStack[i];
      str += `State${state} - ${
        // @ts-ignore
        token.lexeme ?? GrammarUtils.toString(token)
      }; `;
    }
    str += `State${this.traceBackStack[this.traceBackStack.length - 1]} --- ${
      nextToken.lexeme
    }`;
    console.log(str);
  }
}