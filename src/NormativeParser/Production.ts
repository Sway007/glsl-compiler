import GSymbol, { Derivation } from './Symbol';

export default class Production {
  private static _id = 0;

  nonTerminal: GSymbol;
  derivation: Derivation;
  ID: number;
  constructor(nonTerminal: GSymbol, derivation: Derivation) {
    this.ID = Production._id++;
    this.nonTerminal = nonTerminal;
    this.derivation = derivation;
  }

  toString(pos?: number) {
    return `${this.nonTerminal.text}${
      pos !== undefined ? `(${pos})` : ''
    }: ${this.derivation.map((item) => item.text).join(' ')}`;
  }
}
