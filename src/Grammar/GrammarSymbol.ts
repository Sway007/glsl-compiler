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
  L,
  R,
  exp,
  term,
  factor,
  program,
  statements,
  statement,
  declaration,
  assignment,
  block,
  type,
  ifStmt,
  elsePart,
  init,
  condition,
  relOp,
  logicExp,
  // TEST: end
}

export type GrammarSymbol = Terminal | ENonTerminal;

export type Derivation = GrammarSymbol[];
