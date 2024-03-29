import Grammar from '../Grammar';
import GSymbol, { eof } from '../Symbol';

const LP = GSymbol.create('(', false);
const RP = GSymbol.create(')', false);
const Plus = GSymbol.create('+', false);
const Star = GSymbol.create('*', false);
const ID = GSymbol.create('id', false);

const F = GSymbol.create('F', true);
const THat = GSymbol.create('T`', true);
const T = GSymbol.create('T', true);
const EHat = GSymbol.create('E`', true);
const E = GSymbol.create('E', true);

const grammar = new Grammar(E);
grammar.addProduction(E, [T, EHat]);
grammar.addProduction(EHat, [Plus, T, EHat]);
grammar.addProduction(EHat, [eof]);
grammar.addProduction(T, [F, THat]);
grammar.addProduction(THat, [Star, F, THat]);
grammar.addProduction(THat, [eof]);
grammar.addProduction(F, [LP, E, RP]);
grammar.addProduction(F, [ID]);

export default grammar;
