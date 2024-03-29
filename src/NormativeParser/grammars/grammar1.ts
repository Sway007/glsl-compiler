import Grammar from '../Grammar';
import GSymbol, { eof } from '../Symbol';

const S = GSymbol.create('S', true);
const A = GSymbol.create('A', true);
const B = GSymbol.create('B', true);
const BHat = GSymbol.create('B`', true);
const C = GSymbol.create('C', true);

const a = GSymbol.create('a', false);
const b = GSymbol.create('b', false);
const c = GSymbol.create('c', false);

const grammar = new Grammar(S);
grammar.addProduction(S, [A, B]);
grammar.addProduction(A, [C, a]);
grammar.addProduction(A, [eof]);
grammar.addProduction(B, [c, BHat]);
grammar.addProduction(BHat, [a, A, C, BHat]);
grammar.addProduction(BHat, [eof]);
grammar.addProduction(C, [b]);
grammar.addProduction(C, [eof]);

export default grammar;
