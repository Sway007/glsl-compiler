import Grammar from '../Grammar';
import GSymbol, { eof } from '../Symbol';

const n = GSymbol.create('n', false);
const plus = GSymbol.create('+', false);

const S = GSymbol.create('S', true);
const E = GSymbol.create('E', true);
const T = GSymbol.create('T', true);

const grammar = new Grammar(S);
grammar.addProduction(S, [E]);
grammar.addProduction(E, [T, plus, E]);
grammar.addProduction(E, [T]);
grammar.addProduction(T, [n]);

export const terminalSymbols = [n, plus, eof];
export const nonTerminalSymbols = [S, E, T];

export default grammar;
