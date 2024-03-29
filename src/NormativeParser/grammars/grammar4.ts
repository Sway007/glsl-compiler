import Grammar from '../Grammar';
import GSymbol, { eof } from '../Symbol';

const x = GSymbol.create('x', false);
const y = GSymbol.create('y', false);

const S = GSymbol.create('S', true);
const T = GSymbol.create('T', true);

const grammar = new Grammar(S);
grammar.addProduction(S, [x, x, T]);
grammar.addProduction(T, [y]);

export const terminalSymbols = [x, y, eof];
export const nonTerminalSymbols = [S, T];

export default grammar;
