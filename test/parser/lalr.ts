import { readFileSync } from 'fs';
import Grammar from '../../src/Grammar';
import { ENonTerminal } from '../../src/Grammar/GrammarSymbol';
import { EKeyword, ETokenType } from '../../src/Lexer/TokenType';
import LREncoder from '../../src/ParserGenerator/Encoder';
import LALR1 from '../../src/ParserGenerator/LALR1';
import LRLoader from '../../src/ParserGenerator/Loader';
import { printFirstSet, printStatePool, printStateTable } from './utils';
import Lexer from '../../src/Lexer';
// import testCase from './cases/arithmetic';
// import testCase from './cases/circle';
import testCase from './cases/typeCheck';

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

// const grammar = Grammar.create(ENonTerminal.A, [
//   [ENonTerminal.A, ENonTerminal.F, ENonTerminal.C, ETokenType.a],
//   [ENonTerminal.A, ENonTerminal.E, ENonTerminal.A],
//   [ENonTerminal.B, ENonTerminal.C, ENonTerminal.G, ETokenType.h],
//   [ENonTerminal.C, ENonTerminal.D, ENonTerminal.B, ETokenType.a],
//   [ENonTerminal.C, ETokenType.b, ETokenType.h],
//   [ENonTerminal.C, ETokenType.c],
//   [ENonTerminal.C, ETokenType.EPSILON],
//   [ENonTerminal.D, ENonTerminal.F, ETokenType.e],
//   [ENonTerminal.D, ETokenType.EPSILON],
//   [ENonTerminal.E, ENonTerminal.G, ETokenType.h],
//   [ENonTerminal.E, ENonTerminal.D, ETokenType.f],
//   [ENonTerminal.F, ENonTerminal.E, ENonTerminal.A],
//   [ENonTerminal.F, ETokenType.d, ENonTerminal.F],
//   [ENonTerminal.F, ETokenType.EPSILON],
//   [ENonTerminal.G, ETokenType.g],
// ]);

// const printConfig = {
//   terminalSymbols: [
//     ETokenType.a,
//     ETokenType.b,
//     ETokenType.c,
//     ETokenType.d,
//     ETokenType.e,
//     ETokenType.f,
//     ETokenType.g,
//     ETokenType.EOF,
//   ],
//   nonTerminalSymbols: [
//     ENonTerminal.A,
//     ENonTerminal.B,
//     ENonTerminal.C,
//     ENonTerminal.D,
//     ENonTerminal.E,
//     ENonTerminal.F,
//     ENonTerminal.G,
//   ],
// };

// const grammar = Grammar.create(ENonTerminal.S, [
//   [ENonTerminal.S, ENonTerminal.L, ETokenType.EQUAL, ENonTerminal.R],
//   [ENonTerminal.S, ENonTerminal.R],
//   [ENonTerminal.L, ETokenType.STAR, ENonTerminal.R],
//   [ENonTerminal.L, ETokenType.ID],
//   [ENonTerminal.R, ENonTerminal.L],
// ]);

// const printConfig = {
//   nonTerminalSymbols: [ENonTerminal.S, ENonTerminal.T, ENonTerminal.R],
//   terminalSymbols: [ETokenType.EQUAL, ETokenType.STAR, ETokenType.ID],
// };

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

// const grammar = Grammar.create(ENonTerminal.S, [
//   [ENonTerminal.S, ENonTerminal.C, ENonTerminal.C],
//   [ENonTerminal.C, ETokenType.c, ENonTerminal.C],
//   [ENonTerminal.C, ETokenType.d],
// ]);

// const printConfig = {
//   terminalSymbols: [ETokenType.c, ETokenType.d, ETokenType.EOF],
//   nonTerminalSymbols: [ENonTerminal.S, ENonTerminal.C],
// };

const grammar = testCase.createGrammar();

const parser = new LALR1(grammar);
parser.generate();

printFirstSet(parser.firstSetMap);
printStatePool();
printStateTable(testCase.printConfig, parser);
LREncoder.encode('lalr1.bin', parser);

console.log('decoding ....');
const buffer = readFileSync('lalr1.bin');
const arraybuffer = new ArrayBuffer(buffer.byteLength);
const view = new DataView(arraybuffer);
for (let i = 0; i < buffer.byteLength; i++) {
  view.setUint8(i, buffer[i]);
}

const decodedParser = LRLoader.load(arraybuffer, grammar);
printStateTable(testCase.printConfig, decodedParser);

const lexer = new Lexer(testCase.source);
const tokens = lexer.tokenize();
testCase.addTranslationRule(grammar);
decodedParser.parse(tokens);
