import Grammar from './Grammar';
import Production from './Production';
import GSymbol from './Symbol';

export class ParsingStateItem {
  production: Production;
  position: number;

  /** Next symbol */
  get peek() {
    return this.production.derivation[this.position];
  }

  /** Current symbol */
  get curSymbol() {
    return this.production.derivation[this.position - 1];
  }

  get canReduce() {
    return this.position > this.production.derivation.length - 1;
  }

  get reduceStep() {
    return this.production.derivation.length;
  }

  get ID() {
    return ParsingStateItem.getID(this.production, this.position);
  }

  private static pool: Map<string /** ID */, ParsingStateItem> = new Map();

  static getID(production: Production, position: number) {
    return `${production.ID},${position}`;
  }

  static getItem(production: Production, position: number) {
    const id = this.getID(production, position);
    let item = this.pool.get(id);
    if (!item) {
      item = new ParsingStateItem(production, position);
      this.pool.set(id, item);
    }
    return item;
  }

  private constructor(production: Production, position: number) {
    this.production = production;
    this.position = position;
  }

  advance() {
    if (this.canReduce) throw `Error: advance reduce-able parsing state item`;
    const item = ParsingStateItem.getItem(this.production, this.position + 1);
    return item;
  }

  toString() {
    return this.production.toString(this.position);
  }
}

export enum EParsingAction {
  Shift,
  Reduce,
  Accept,
}

export interface ActionInfo {
  action: EParsingAction;
  state?: number;
}

export default class ParsingState {
  private static id = 0;
  static pool: Map<number /** id */, ParsingState> = new Map();
  static closureStateMap: Map<
    string /** PreState.ID + Symbol.ID */,
    ParsingState
  > = new Map();
  static getByID(id: number) {
    return this.pool.get(id);
  }

  readonly ID: number;
  readonly items: Map<GSymbol, ParsingStateItem[]> = new Map();

  extended: boolean = false;

  /** identified by cores */
  static createClosureState(cores: ParsingStateItem[], grammar: Grammar) {
    const mapKey = cores.map((item) => item.ID).join(',');
    const state = ParsingState.closureStateMap.get(mapKey)!;
    if (state) {
      return state;
    }

    const newState = new ParsingState();
    for (const item of cores) {
      newState.addItem(item.production.nonTerminal, item, grammar);
    }
    ParsingState.pool.set(newState.ID, newState);
    ParsingState.closureStateMap.set(mapKey, newState);
    return newState;
  }

  private constructor() {
    this.ID = ParsingState.id++;
  }

  addItem(nt: GSymbol, item: ParsingStateItem, grammar: Grammar) {
    if (this._addItem(nt, item)) {
      this._closure(item, grammar);
    }
  }

  private _closure(item: ParsingStateItem, grammar: Grammar) {
    const nt = item.peek;
    if (!nt || !nt.nonTerminal) return;

    const productionList = grammar.getProductions(nt);
    if (!productionList) throw `Error: no production for ${nt}`;
    for (const production of productionList) {
      const psItem = ParsingStateItem.getItem(production, 0);
      if (this._addItem(nt, psItem)) {
        this._closure(psItem, grammar);
      }
    }
  }

  private _addItem(nt: GSymbol, item: ParsingStateItem) {
    const itemList = this.items.get(nt) ?? [];
    if (itemList.find((i) => i === item)) return false;
    itemList.push(item);
    this.items.set(nt, itemList);
    return true;
  }
}
