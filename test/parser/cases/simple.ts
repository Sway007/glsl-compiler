import Grammar from '../../../src/Grammar';
import { ENonTerminal } from '../../../src/Grammar/GrammarSymbol';
import Token from '../../../src/Lexer/Token';
import { EKeyword, ETokenType } from '../../../src/Lexer/TokenType';
import { DeclarationAst, EType } from '../../../src/Parser/AST';
import SematicAnalyzer from '../../../src/Parser/SemanticAnalyzer';
import SymbolTable, { SymbolInfo } from '../../../src/Parser/SymbolTable';
import { LocRange } from '../../../src/common/Position';
import { TestCase } from '../types';

const createGrammar = () =>
  Grammar.create(ENonTerminal.statements, [
    /** 0 */ [ENonTerminal.statements, ENonTerminal.statement],
    /** 1 */ [
      ENonTerminal.statements,
      ENonTerminal.statements,
      ENonTerminal.statement,
    ],
    /** 2 */ [ENonTerminal.statement, ENonTerminal.declaration],
    /** 3 */ [ENonTerminal.statement, ENonTerminal.assignment],
    /** 4 */ [ENonTerminal.statement, ENonTerminal.block],
    /** 5 */ [
      ENonTerminal.declaration,
      ENonTerminal.type,
      ETokenType.ID,
      ETokenType.SEMICOLON,
    ],
    /** 6 */ [
      ENonTerminal.assignment,
      ETokenType.ID,
      ETokenType.EQUAL,
      ENonTerminal.exp,
      ETokenType.SEMICOLON,
    ],
    /** 7 */ [
      ENonTerminal.block,
      ETokenType.LEFT_BRACE,
      ENonTerminal.statements,
      ETokenType.RIGHT_BRACE,
    ],
    /** 8 */ [
      ENonTerminal.exp,
      ENonTerminal.exp,
      ETokenType.PLUS,
      ENonTerminal.term,
    ],
    /** 9 */ [
      ENonTerminal.exp,
      ENonTerminal.exp,
      ETokenType.DASH,
      ENonTerminal.term,
    ],
    /** 10 */ [ENonTerminal.exp, ENonTerminal.term],
    /** 11 */ [
      ENonTerminal.term,
      ENonTerminal.term,
      ETokenType.STAR,
      ENonTerminal.factor,
    ],
    /** 12 */ [
      ENonTerminal.term,
      ENonTerminal.term,
      ETokenType.SLASH,
      ENonTerminal.factor,
    ],
    /** 13 */ [ENonTerminal.term, ENonTerminal.factor],
    /** 14 */ [ENonTerminal.factor, ETokenType.INT_CONSTANT],
    /** 15 */ [
      ENonTerminal.factor,
      ETokenType.LEFT_PAREN,
      ENonTerminal.exp,
      ETokenType.RIGHT_PAREN,
    ],
    /** 16 */ [ENonTerminal.factor, ETokenType.ID],
    /** 17 */ [ENonTerminal.type, EKeyword.INT],
    /** 18 */ [ENonTerminal.type, EKeyword.FLOAT],

    /** 19 */ [ENonTerminal.type, EKeyword.BOOL],
  ]);

const addTranslationRule = (sa: SematicAnalyzer) => {
  sa.addTranslationRule(5, (sa, t, token, semi) => {
    const type = sa.semanticStack.pop() as EType;
    const start = (<Token>t).position;
    const end = (<Token>semi).position.offset((<Token>semi).length);
    const location = new LocRange(start, end);
    const ast = new DeclarationAst(location, (<Token>token).lexeme, t as any);

    const symbolInfo = new SymbolInfo(type, ast);

    sa.scope.newSymbol((<Token>token).lexeme, symbolInfo);
  });
  sa.addTranslationRule(16, (sa, token) => {
    const id = (token as Token).lexeme;
    const idInfo = sa.scope.getSymbol(id);
    if (!idInfo) {
      sa.log('undeclared identifier', id);
    }
  });
  sa.addTranslationRule(17, (sa) => {
    sa.semanticStack.push(EType.int);
  });
  sa.addTranslationRule(18, (sa) => {
    sa.semanticStack.push(EType.float);
  });
  sa.addTranslationRule(19, (sa) => {
    sa.semanticStack.push(EType.bool);
  });
};

const printConfig = {
  terminalSymbols: [
    ETokenType.INT_CONSTANT,
    ETokenType.LEFT_PAREN,
    ETokenType.RIGHT_PAREN,
    ETokenType.PLUS,
    ETokenType.DASH,
    ETokenType.STAR,
    ETokenType.SLASH,
    ETokenType.LEFT_BRACE,
    ETokenType.RIGHT_BRACE,
    ETokenType.ID,
    ETokenType.EQUAL,
    ETokenType.EOF,
    EKeyword.BOOL,
    EKeyword.INT,
    EKeyword.FLOAT,
  ],
  nonTerminalSymbols: [
    ENonTerminal.exp,
    ENonTerminal.term,
    ENonTerminal.factor,
    ENonTerminal.statements,
    ENonTerminal.statement,
    ENonTerminal.declaration,
    ENonTerminal.assignment,
    ENonTerminal.block,
    ENonTerminal.type,
  ],
};

const source = `
int v1;
v1 = 10 + 2 /3;

// undeclared variable
v4 = v1 + v2 + v4;
{
  float v3;
  v3 = v1 + v2;
  v2 = v5;
}
`;

const testCase: TestCase = {
  source,
  addTranslationRule,
  createGrammar,
  printConfig,
};

export default testCase;
