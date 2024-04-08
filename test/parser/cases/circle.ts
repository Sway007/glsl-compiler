import Grammar from '../../../src/Grammar';
import { ENonTerminal } from '../../../src/Grammar/GrammarSymbol';
import Token from '../../../src/Lexer/Token';
import { ETokenType } from '../../../src/Lexer/TokenType';
import { TestCase } from '../types';

const createGrammar = () =>
  Grammar.create(ENonTerminal.A, [
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

export default { createGrammar, printConfig };
