import Grammar from '../../src/Grammar';
import { ENonTerminal } from '../../src/Grammar/GrammarSymbol';
import { EKeyword, ETokenType } from '../../src/Lexer/TokenType';
import LALR1 from '../../src/ParserGenerator/LALR1';

// const grammar = Grammar.create(ENonTerminal.E, [
//   [ENonTerminal.E, ENonTerminal.T, ENonTerminal.X],
//   [ENonTerminal.X, ETokenType.PLUS, ENonTerminal.E],
//   [ENonTerminal.X, ETokenType.EPSILON],
//   [ENonTerminal.T, EKeyword.INT, ENonTerminal.Y],
//   [
//     ENonTerminal.T,
//     ETokenType.LEFT_PAREN,
//     ENonTerminal.E,
//     ETokenType.RIGHT_PAREN,
//   ],
//   [ENonTerminal.Y, ETokenType.STAR, ENonTerminal.T],
//   [ENonTerminal.Y, ETokenType.EPSILON],
// ]);

// const grammar = Grammar.create(ENonTerminal.S, [
//   [ENonTerminal.S, ENonTerminal.X, ENonTerminal.X],
//   [ENonTerminal.X, ETokenType.a, ENonTerminal.X],
//   [ENonTerminal.X, ETokenType.b],
// ]);
// const printConfig = {
//   terminalSymbols: [ETokenType.a, ETokenType.b, ETokenType.EOF],
//   nonTerminalSymbols: [ENonTerminal.S, ENonTerminal.X],
// };

const grammar = Grammar.create(ENonTerminal.A, [
  [ENonTerminal.A, ENonTerminal.F, ENonTerminal.C, ETokenType.a],
  [ENonTerminal.A, ENonTerminal.E, ENonTerminal.A],
  [ENonTerminal.B, ENonTerminal.C, ENonTerminal.G, ETokenType.h],
  [ENonTerminal.C, ENonTerminal.D, ENonTerminal.B, ETokenType.a],
  [ENonTerminal.C, ETokenType.b, ETokenType.h],
  [ENonTerminal.C, ETokenType.c],
  [ENonTerminal.C, ETokenType.EPSILON],
  [ENonTerminal.D, ENonTerminal.F, ETokenType.e],
  [ENonTerminal.D, ETokenType.EPSILON],
  [ENonTerminal.E, ENonTerminal.G, ETokenType.h],
  [ENonTerminal.E, ENonTerminal.D, ETokenType.f],
  [ENonTerminal.F, ENonTerminal.E, ENonTerminal.A],
  [ENonTerminal.F, ETokenType.d, ENonTerminal.F],
  [ENonTerminal.F, ETokenType.EPSILON],
  [ENonTerminal.G, ETokenType.g],
]);

const printConfig = {
  terminalSymbols: [
    ETokenType.a,
    ETokenType.b,
    ETokenType.c,
    ETokenType.d,
    ETokenType.e,
    ETokenType.f,
    ETokenType.g,
    ETokenType.EOF,
  ],
  nonTerminalSymbols: [
    ENonTerminal.A,
    ENonTerminal.B,
    ENonTerminal.C,
    ENonTerminal.D,
    ENonTerminal.E,
    ENonTerminal.F,
    ENonTerminal.G,
  ],
};

// const grammar = Grammar.create(ENonTerminal.S, [
//   [ENonTerminal.S, ENonTerminal.E],
//   [ENonTerminal.E, ENonTerminal.T, ETokenType.PLUS, ENonTerminal.E],
//   [ENonTerminal.E, ENonTerminal.T],
//   [ENonTerminal.T, ETokenType.n],
// ]);

// const printConfig = {
//   terminalSymbols: [ETokenType.n, ETokenType.PLUS, ETokenType.EOF],
//   nonTerminalSymbols: [ENonTerminal.S, ENonTerminal.E, ENonTerminal.T],
// };

const parser = new LALR1(grammar);
parser.generate();

// TEST:
parser.printParsingTable(printConfig);
parser.serialize();
