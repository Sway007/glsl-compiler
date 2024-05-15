import Grammar from '../../../src/Grammar';
import { ENonTerminal } from '../../../src/Grammar/GrammarSymbol';
import Token from '../../../src/Lexer/Token';
import { EKeyword, ETokenType } from '../../../src/Lexer/TokenType';
import SematicAnalyzer from '../../../src/Parser/SemanticAnalyzer';
import { TestCase } from '../types';

const createGrammar = () =>
  Grammar.create(ENonTerminal.exp, [
    [ENonTerminal.exp, ENonTerminal.exp, ETokenType.PLUS, ENonTerminal.term],
    [ENonTerminal.exp, ENonTerminal.exp, ETokenType.AND_OP, ENonTerminal.term],
    [ENonTerminal.exp, ENonTerminal.exp, ETokenType.EQ_OP, ENonTerminal.term],
    [ENonTerminal.exp, ENonTerminal.term],
    [ENonTerminal.term, EKeyword.BOOL],
    [ENonTerminal.term, ETokenType.INT_CONSTANT],
    [
      ENonTerminal.term,
      ETokenType.LEFT_PAREN,
      ENonTerminal.exp,
      ETokenType.RIGHT_PAREN,
    ],
  ]);

enum EType {
  BOOL = 'BOOL',
  INT = 'INT',
  ERROR = 'ERROR',
}

const addTranslationRule = (sa: SematicAnalyzer) => {
  const valueStack: EType[] = [];
  sa.addTranslationRule(5, () => {
    valueStack.push(EType.INT);
  });
  sa.addTranslationRule(4, () => {
    valueStack.push(EType.BOOL);
  });
  sa.addTranslationRule(0, (_, __, term) => {
    const termType = valueStack.pop();
    const expType = valueStack.pop();
    if (termType === EType.INT && termType === expType) {
      valueStack.push(EType.INT);
    } else {
      console.error('type error at', (<Token>term).position);
      valueStack.push(EType.ERROR);
    }
  });
  sa.addTranslationRule(1, (_, __, term) => {
    const termType = valueStack.pop();
    const expType = valueStack.pop();
    if (termType === EType.BOOL && termType === expType) {
      valueStack.push(EType.BOOL);
    } else {
      console.error('type error at', (<Token>term).position);
      valueStack.push(EType.ERROR);
    }
  });
  sa.addTranslationRule(2, (_, __, term) => {
    const termType = valueStack.pop()!;
    const expType = valueStack.pop();
    if (termType === expType && termType !== EType.ERROR) {
      valueStack.push(EType.BOOL);
    } else {
      console.error('type error at', (<Token>term).position);
      valueStack.push(EType.ERROR);
    }
  });
  sa.acceptRule = () => {
    console.log('Return type is', EType[valueStack[0]]);
  };
};

const printConfig = {
  terminalSymbols: [
    ETokenType.INT_CONSTANT,
    ETokenType.LEFT_PAREN,
    ETokenType.RIGHT_PAREN,
    EKeyword.BOOL,
    ETokenType.PLUS,
    ETokenType.AND_OP,
    ETokenType.EQ_OP,
  ],
  nonTerminalSymbols: [
    ENonTerminal.exp,
    ENonTerminal.term,
    ENonTerminal.factor,
  ],
};

const source = '( 2 + 2 ) == 4 && (3 == 4)';

const testCase: TestCase = {
  source,
  printConfig,
  createGrammar,
  addTranslationRule,
};

export default testCase;
