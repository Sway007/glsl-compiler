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
import { ASTNode, TreeNode } from './AST';
import SematicAnalyzer from './SemanticAnalyzer';
import { TraceStackItem } from './types';

export default class Parser {
  readonly actionTable: StateActionTable;
  readonly gotoTable: StateGotoTable;
  readonly grammar: Grammar;
  readonly sematicAnalyzer: SematicAnalyzer;
  private traceBackStack: (TraceStackItem | number)[] = [];

  private get curState() {
    return this.traceBackStack[this.traceBackStack.length - 1] as number;
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

  parse(tokens: Generator<Token, Token>, debug = false) {
    const start = performance.now();
    const { traceBackStack, sematicAnalyzer } = this;
    traceBackStack.push(0);

    let nextToken = tokens.next();
    let loopCount = 0;
    while (true) {
      loopCount += 1;
      const token = nextToken.value;

      const actionInfo = this.stateActionTable.get(token.type);
      if (actionInfo?.action === EAction.Shift) {
        traceBackStack.push(token, actionInfo.target!);
        nextToken = tokens.next();
        debug && this.printStack(nextToken.value);
      } else if (actionInfo?.action === EAction.Accept) {
        console.log(
          `Accept! State automata run ${loopCount} times! cost time ${
            performance.now() - start
          }ms`
        );
        sematicAnalyzer.acceptRule?.(sematicAnalyzer);
        return sematicAnalyzer.semanticStack.pop() as ASTNode.GLShaderProgram;
      } else if (actionInfo?.action === EAction.Reduce) {
        const target = actionInfo.target!;
        const reduceProduction = this.grammar.getProductionByID(target)!;
        debug && console.log(`Reduce: ${reduceProduction.toString()}`);
        const translationRule = sematicAnalyzer.getTranslationRule(
          reduceProduction.id
        );

        const values: (TreeNode | Token)[] = [];

        for (let i = reduceProduction.derivation.length - 1; i >= 0; i--) {
          if (reduceProduction.derivation[i] === ETokenType.EPSILON) continue;
          traceBackStack.pop();
          const token = traceBackStack.pop();
          if (token instanceof Token) {
            values.unshift(token);
          } else {
            const astNode = sematicAnalyzer.semanticStack.pop()!;
            values.unshift(astNode);
          }
        }
        debug && this.printStack(token);
        translationRule?.(sematicAnalyzer, ...values);

        const gotoTable = this.stateGotoTable;
        traceBackStack.push(reduceProduction.goal);

        const nextState = gotoTable?.get(reduceProduction.goal)!;
        traceBackStack.push(nextState);
        debug && this.printStack(token);
        continue;
      } else {
        console.error('parse error at', token.position);
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
