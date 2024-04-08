import Grammar from '../../../src/Grammar';
import { ENonTerminal } from '../../../src/Grammar/GrammarSymbol';
import Token from '../../../src/Lexer/Token';
import { ETokenType } from '../../../src/Lexer/TokenType';
import { TestCase } from '../types';

const createGrammar = () =>
  Grammar.create(ENonTerminal.exp, [
    [ENonTerminal.exp, ENonTerminal.exp, ETokenType.PLUS, ENonTerminal.term],
    [ENonTerminal.exp, ENonTerminal.term],
    [
      ENonTerminal.term,
      ENonTerminal.term,
      ETokenType.STAR,
      ENonTerminal.factor,
    ],
    [ENonTerminal.term, ENonTerminal.factor],
    [ENonTerminal.factor, ETokenType.INT_CONSTANT],
    [
      ENonTerminal.factor,
      ETokenType.LEFT_PAREN,
      ENonTerminal.exp,
      ETokenType.RIGHT_PAREN,
    ],
  ]);

const addTranslationRule = (grammar: Grammar) => {
  const valueStack: number[] = [];
  Grammar.acceptRule = () => {
    console.log('Sum is', valueStack[0]);
  };
  Grammar.addTranslationRule(0, () => {
    const value = valueStack.pop()! + valueStack.pop()!;
    valueStack.push(value);
  });
  Grammar.addTranslationRule(4, (id) => {
    valueStack.push(Number((<Token>id).lexeme));
  });
  Grammar.addTranslationRule(2, () => {
    const value = valueStack.pop()! * valueStack.pop()!;
    valueStack.push(value);
  });
};

const printConfig = {
  terminalSymbols: [
    ETokenType.INT_CONSTANT,
    ETokenType.LEFT_PAREN,
    ETokenType.RIGHT_PAREN,
    ETokenType.PLUS,
    ETokenType.STAR,
    ETokenType.EOF,
  ],
  nonTerminalSymbols: [
    ENonTerminal.exp,
    ENonTerminal.term,
    ENonTerminal.factor,
  ],
};

const source = '  2 *   ((4+5) + 10) + 10';

const testCase: TestCase = {
  source,
  printConfig,
  createGrammar,
  addTranslationRule,
};

export default testCase;
