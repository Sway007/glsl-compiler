import { ENonTerminal, GrammarSymbol, Terminal } from './GrammarSymbol';
import Production from './Production';
import GrammarUtils from './Utils';

export default class StateItem {
  static pool: Map<string /** Map ID */, StateItem> = new Map();
  private static _id = 0;

  static create(production: Production, position: number, lookahead: Terminal) {
    const mapId = StateItem.getID(production, position, lookahead);
    const item = StateItem.pool.get(mapId);
    return item ?? new StateItem(production, position, lookahead);
  }

  static getID(production: Production, position: number, lookahead: Terminal) {
    return `${production.id},${position},${lookahead}`;
  }

  readonly production: Production;
  readonly position: number;
  readonly lookahead: Terminal;
  readonly id: number;
  get curSymbol() {
    return this.production.derivation[this.position];
  }
  get nextSymbol() {
    return this.production.derivation[this.position + 1];
  }

  private constructor(
    production: Production,
    position: number,
    lookahead: Terminal
  ) {
    this.production = production;
    this.position = position;
    this.lookahead = lookahead;
    this.id = StateItem._id++;

    StateItem.pool.set(
      StateItem.getID(this.production, this.position, this.lookahead),
      this
    );
  }

  canReduce() {
    return this.position > this.production.derivation.length - 1;
  }

  advance() {
    if (this.canReduce()) throw `Error: advance reduce-able parsing state item`;
    return StateItem.create(this.production, this.position + 1, this.lookahead);
  }

  toString() {
    const coreItem = this.production.derivation.map((item) =>
      GrammarUtils.toString(item)
    );
    coreItem[this.position] = '.' + (coreItem[this.position] ?? '');

    return `${ENonTerminal[this.production.goal]} :=> ${coreItem.join(
      '|'
    )} ;${GrammarUtils.toString(this.lookahead)}`;
  }
}
