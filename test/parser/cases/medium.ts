import Grammar from '../../../src/Grammar';
import {
  ENonTerminal,
  GrammarSymbol,
} from '../../../src/Grammar/GrammarSymbol';
import Token from '../../../src/Lexer/Token';
import { EKeyword, ETokenType } from '../../../src/Lexer/TokenType';
import { DeclarationAst, EType } from '../../../src/Parser/AST';
import SematicAnalyzer, {
  TranslationRule,
} from '../../../src/Parser/SemanticAnalyzer';
import { SymbolInfo } from '../../../src/Parser/SymbolTable';
import { LocRange } from '../../../src/common/Position';
import { TestCase } from '../types';

const productionAndRules: [GrammarSymbol[], TranslationRule | null][] = [
  [
    [
      ENonTerminal.block,
      ETokenType.LEFT_BRACE,
      ENonTerminal.statements,
      ETokenType.RIGHT_BRACE,
    ],
    (sa) => {},
  ],
  [
    [ENonTerminal.statements, ENonTerminal.statement, ENonTerminal.statements],
    (sa) => {},
  ],
  [[ENonTerminal.statements, ETokenType.EPSILON], null],
  [
    [ENonTerminal.statement, ENonTerminal.assignment, ETokenType.SEMICOLON],
    null,
  ],
  [
    [ENonTerminal.statement, ENonTerminal.declaration, ETokenType.SEMICOLON],
    null,
  ],
  [[ENonTerminal.statement, ENonTerminal.exp, ETokenType.SEMICOLON], null],
  [[ENonTerminal.statement, ENonTerminal.ifStmt], null],
  [
    [
      ENonTerminal.assignment,
      ETokenType.ID,
      ETokenType.EQUAL,
      ENonTerminal.exp,
    ],
    (sa) => {},
  ],
  [
    [
      ENonTerminal.ifStmt,
      EKeyword.IF,
      ETokenType.LEFT_PAREN,
      ENonTerminal.condition,
      ETokenType.RIGHT_PAREN,
      ENonTerminal.block,
      ENonTerminal.elsePart,
    ],
    (sa) => {},
  ],
  [[ENonTerminal.elsePart, EKeyword.ELSE, ENonTerminal.block], (sa) => {}],
  [[ENonTerminal.elsePart, ETokenType.EPSILON], null],
  [
    [
      ENonTerminal.declaration,
      ENonTerminal.type,
      ETokenType.ID,
      ENonTerminal.init,
    ],
    (sa) => {},
  ],
  [[ENonTerminal.init, ETokenType.EQUAL, ENonTerminal.exp], (sa) => {}],
  [[ENonTerminal.init, ETokenType.EPSILON], null],
  [[ENonTerminal.type, EKeyword.INT], (sa) => {}],
  [[ENonTerminal.type, EKeyword.FLOAT], (sa) => {}],
  [[ENonTerminal.type, EKeyword.BOOL], (sa) => {}],
  [
    [ENonTerminal.exp, ENonTerminal.exp, ETokenType.PLUS, ENonTerminal.term],
    (sa) => {},
  ],
  [
    [ENonTerminal.exp, ENonTerminal.exp, ETokenType.DASH, ENonTerminal.term],
    (sa) => {},
  ],
  [[ENonTerminal.exp, ENonTerminal.term], null],
  [
    [
      ENonTerminal.term,
      ENonTerminal.term,
      ETokenType.STAR,
      ENonTerminal.factor,
    ],
    (sa) => {},
  ],
  [
    [
      ENonTerminal.term,
      ENonTerminal.term,
      ETokenType.SLASH,
      ENonTerminal.factor,
    ],
    (sa) => {},
  ],
  [[ENonTerminal.term, ENonTerminal.factor], null],
  [
    [
      ENonTerminal.factor,
      ETokenType.LEFT_PAREN,
      ENonTerminal.exp,
      ETokenType.RIGHT_PAREN,
    ],
    (sa) => {},
  ],
  [[ENonTerminal.factor, ETokenType.ID], (sa) => {}],
  [[ENonTerminal.factor, ETokenType.INT_CONSTANT], (sa) => {}],
  [[ENonTerminal.factor, ETokenType.FLOAT_CONSTANT], (sa) => {}],
  [[ENonTerminal.factor, EKeyword.TRUE], (sa) => {}],
  [[ENonTerminal.factor, EKeyword.FALSE], (sa) => {}],
  [[ENonTerminal.factor, ENonTerminal.condition], (sa) => {}],
  [[ENonTerminal.relOp, ETokenType.LEFT_ANGLE], null],
  [[ENonTerminal.relOp, ETokenType.RIGHT_ANGLE], null],
  [[ENonTerminal.relOp, ETokenType.EQ_OP], null],
  [[ENonTerminal.relOp, ETokenType.NE_OP], null],
  [[ENonTerminal.relOp, ETokenType.GE_OP], null],
  [[ENonTerminal.relOp, ETokenType.LE_OP], null],
  [
    [ENonTerminal.condition, ETokenType.ID, ENonTerminal.relOp, ETokenType.ID],
    (sa, id1, op, id2) => {
      console.log(id1, op, id2);
    },
  ],
];

const createGrammar = () =>
  Grammar.create(
    ENonTerminal.block,
    productionAndRules.map((item) => item[0])
  );

const addTranslationRule = (sa: SematicAnalyzer) => {
  for (let i = 0; i < productionAndRules.length; i++) {
    const rule = productionAndRules[i][1];
    if (rule) {
      sa.addTranslationRule(i, rule);
    }
  }
};

const source = `
{
  int v1 = 20;
  int v2;

  v2 = v1 * (1+v1) - 2;
  if (v2 > v1) {
    float v3 = v1 + v2;
  } else {
    v2 = 99;
    v4 = v3 + 2;
  } 
}
`;

const testCase: TestCase = {
  createGrammar,
  addTranslationRule,
  printConfig: undefined,
  source,
};

export default testCase;
