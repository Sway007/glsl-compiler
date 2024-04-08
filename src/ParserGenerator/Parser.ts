import Grammar from '../Grammar';
import { ENonTerminal, Terminal } from '../Grammar/GrammarSymbol';
import Production from '../Grammar/Production';
import GrammarUtils from '../Grammar/Utils';
import Token from '../Lexer/Token';
import { EAction, StateActionTable, StateGotoTable } from './common';

export default class Parser {
  readonly actionTable: StateActionTable;
  readonly gotoTable: StateGotoTable;
  readonly grammar: Grammar;
  private semanticStack: (Token | ENonTerminal | number)[] = [];

  private get curState() {
    return this.semanticStack[this.semanticStack.length - 1] as ENonTerminal;
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

  parse(tokens: Generator<Token, Token>) {
    const { semanticStack } = this;
    semanticStack.push(0);

    let nextToken = tokens.next();
    while (true) {
      const token = nextToken.value;
      const actionInfo = this.stateActionTable.get(token.type);
      if (actionInfo?.action === EAction.Shift) {
        semanticStack.push(token, actionInfo.target!);
        nextToken = tokens.next();
        this.printStack(nextToken.value);
      } else if (actionInfo?.action === EAction.Accept) {
        console.log('Accept!');
        if (Grammar.acceptRule) {
          Grammar.acceptRule?.();
        }
        return;
      } else if (actionInfo?.action === EAction.Reduce) {
        const target = actionInfo.target!;
        const reduceProduction = this.grammar.getProductionByID(target)!;
        console.log(`Reduce: ${reduceProduction.toString()}`);
        const map = Grammar.translationRuleMap;
        const translationRule = Grammar.translationRuleMap.get(
          reduceProduction.id
        );

        const values: (Token | ENonTerminal)[] = [];

        for (let i = 0; i < reduceProduction.derivation.length; i++) {
          semanticStack.pop();
          values.unshift(<Token>semanticStack.pop());
        }
        this.printStack(token);
        if (translationRule) {
          translationRule(...values);
        }

        const gotoTable = this.stateGotoTable;
        semanticStack.push(reduceProduction.goal);

        const nextState = gotoTable?.get(reduceProduction.goal)!;
        semanticStack.push(nextState);
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
    for (let i = 0; i < this.semanticStack.length - 1; i++) {
      const state = <ENonTerminal>this.semanticStack[i++];
      const token = this.semanticStack[i];
      str += `State${state} - ${
        // @ts-ignore
        token.lexeme ?? GrammarUtils.toString(token)
      }; `;
    }
    str += `State${this.semanticStack[this.semanticStack.length - 1]} --- ${
      nextToken.lexeme
    }`;
    console.log(str);
  }
}
