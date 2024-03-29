import { TokenType } from '../Lexer/TokenType';

export type Terminal = TokenType;

export enum ENonTerminal {
  START = 2000,

  // TEST:
  E,
  T,
  X,
  Y,
  S,
  A,
  F,
  C,
  B,
  D,
  G,
  // TEST: end
}

export type GrammarSymbol = Terminal | ENonTerminal;

export type Derivation = GrammarSymbol[];
