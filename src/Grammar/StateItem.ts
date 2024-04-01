import { ETokenType } from '../Lexer/TokenType';
import { ENonTerminal, Terminal } from './GrammarSymbol';
import Production from './Production';
import GrammarUtils from './Utils';

export default class StateItem {
  private static _id = 0;

  readonly production: Production;
  readonly position: number;
  readonly lookaheadSet: Set<Terminal>;
  readonly id: number;
  get curSymbol() {
    return this.production.derivation[this.position];
  }
  get nextSymbol() {
    return this.production.derivation[this.position + 1];
  }

  constructor(
    production: Production,
    position: number,
    lookahead: Iterable<Terminal>
  ) {
    this.production = production;
    this.position = position;
    this.lookaheadSet = new Set([...lookahead]);
    this.id = StateItem._id++;
  }

  addLookahead(ts: Iterable<Terminal>) {
    for (const t of ts) {
      this.lookaheadSet.add(t);
    }
  }

  symbolByOffset(offset: number) {
    return this.production.derivation[this.position + offset];
  }

  canReduce() {
    return this.position > this.production.derivation.length - 1;
  }

  advance() {
    if (this.canReduce()) throw `Error: advance reduce-able parsing state item`;
    return new StateItem(this.production, this.position + 1, this.lookaheadSet);
  }

  toString() {
    const coreItem = this.production.derivation.map((item) =>
      GrammarUtils.toString(item)
    );
    coreItem[this.position] = '.' + (coreItem[this.position] ?? '');

    return `${ENonTerminal[this.production.goal]} :=> ${coreItem.join(
      '|'
    )} ;${Array.from(this.lookaheadSet)
      .map((item) => GrammarUtils.toString(item))
      .join('/')}`;
  }
}
