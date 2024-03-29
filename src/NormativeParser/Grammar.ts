// import { PSItem } from './ParsingState';
import Production from './Production';
import GSymbol, { Derivation } from './Symbol';
import ParserUtils from './Utils';

export default class Grammar {
  private _productions: Map<GSymbol, Production[]> = new Map();
  get productions() {
    return this._productions;
  }

  private _startGSymbol: GSymbol;
  get startGSymbol() {
    return this._startGSymbol;
  }

  get nonTerminals() {
    return this._productions.keys();
  }

  constructor(start: GSymbol) {
    this._startGSymbol = start;
  }

  addProduction(nonTerminal: GSymbol, derivation: Derivation) {
    const productionList = this.getProductions(nonTerminal) ?? [];

    const production = productionList.find((item) =>
      ParserUtils.equalDerivation(item.derivation, derivation)
    );
    if (production) return production;

    const newP = new Production(nonTerminal, derivation);
    productionList.push(newP);
    this._productions.set(nonTerminal, productionList);
    return newP;
  }

  getProductions(nonTerminal: GSymbol) {
    return this._productions.get(nonTerminal);
  }
}
