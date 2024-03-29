import Grammar from '../Grammar';
import GSymbol, { eof } from '../Symbol';

const LP = GSymbol.create('(', false);
const RP = GSymbol.create(')', false);
const ID = GSymbol.create('id', false);

const PList = GSymbol.create('PList', true);
const IDList = GSymbol.create('IDList', true);

const grammar = new Grammar(PList);
grammar.addProduction(PList, [LP, IDList, RP]);
grammar.addProduction(IDList, [ID]);
grammar.addProduction(IDList, [IDList, ID]);

export const terminalSymbols = [LP, RP, ID, eof];
export const nonTerminalSymbols = [PList, IDList];

export default grammar;
