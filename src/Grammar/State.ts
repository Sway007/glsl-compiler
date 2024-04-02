import { Terminal } from './GrammarSymbol';
import Production from './Production';
import StateItem from './StateItem';

export default class State {
  static closureMap: Map<string /** state mapKey */, State> = new Map();
  static pool: Map<number, State> = new Map();
  static _id = 0;

  readonly id: number;
  readonly cores: Set<StateItem>;
  private _items: Set<StateItem>;
  get items() {
    return this._items;
  }

  closured = false;

  private stateItemPool: Map<string /** Map ID */, StateItem> = new Map();

  static create(cores: StateItem[]) {
    const cacheKey = this.getMapKey(cores);
    const state = this.closureMap.get(cacheKey);
    if (state) {
      for (const core of cores) {
        // merge lookahead
        state.createStateItem(
          core.production,
          core.position,
          core.lookaheadSet
        );
      }
      return state;
    }

    const newState = new State(cores);
    this.closureMap.set(cacheKey, newState);
    return newState;
  }

  static getMapKey(cores: StateItem[]) {
    return cores
      .map((item) => `${item.production.id},${item.position}`)
      .join(';');
  }

  private constructor(cores: Iterable<StateItem>) {
    this.id = State._id++;
    this._items = new Set([...cores]);
    this.cores = new Set([...cores]);
    for (const it of cores) {
      const itemMapKey = this.getStateItemMapKey(it.production, it.position);
      this.stateItemPool.set(itemMapKey, it);
    }
    State.pool.set(this.id, this);
  }

  getStateItemMapKey(production: Production, position: number) {
    return `${production.id},${position}`;
  }

  createStateItem(
    production: Production,
    position: number,
    lookaheadSet: Set<Terminal> = new Set()
  ) {
    const mapId = this.getStateItemMapKey(production, position);
    const item = this.stateItemPool.get(mapId);
    if (item) {
      for (const la of lookaheadSet) {
        item.lookaheadSet.add(la);
      }
      return item;
    }
    const newItem = new StateItem(production, position, lookaheadSet);
    this.stateItemPool.set(mapId, newItem);
    return newItem;
  }
}
