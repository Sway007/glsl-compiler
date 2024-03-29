import Grammar from '../NormativeParser/Grammar';
import GSymbol, { eof } from '../NormativeParser/Symbol';

const LP = GSymbol.create('(', false);
const RP = GSymbol.create(')', false);
const Plus = GSymbol.create('+', false);
const Star = GSymbol.create('*', false);
const Int = GSymbol.create('int', false);

const Y = GSymbol.create('Y', true);
const X = GSymbol.create('X', true);
const T = GSymbol.create('T', true);
const E = GSymbol.create('E', true);

const grammar = new Grammar(E);
grammar.addProduction(E, [T, X]);
grammar.addProduction(X, [Plus, E]);
grammar.addProduction(X, [eof]);
grammar.addProduction(T, [Int, Y]);
grammar.addProduction(T, [LP, E, RP]);
grammar.addProduction(Y, [Star, T]);
grammar.addProduction(Y, [eof]);
