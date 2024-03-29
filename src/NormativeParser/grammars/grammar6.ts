import Grammar from '../Grammar';
import GSymbol, { eof } from '../Symbol';

const a = GSymbol.create('a', false);
const b = GSymbol.create('b', false);
const c = GSymbol.create('c', false);
const d = GSymbol.create('d', false);

const S = GSymbol.create('S', true);
const A = GSymbol.create('A', true);
const B = GSymbol.create('B', true);

const grammar = new Grammar(S);
grammar.addProduction(S, [A]);
grammar.addProduction(A, [a, B, d]);
grammar.addProduction(B, [b, c]);

export const terminalSymbols = [a, b, c, d, eof];
export const nonTerminalSymbols = [A, B];

export default grammar;
