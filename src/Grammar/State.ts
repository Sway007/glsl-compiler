import StateItem from './StateItem';

export default class State {
  static closureMap: Map<string /** state mapKey */, State> = new Map();
  static pool: Map<number, State> = new Map();
  static _id = 0;

  readonly id: number;
  readonly cores: StateItem[];
  private _items: StateItem[] = [];
  get items() {
    return this._items;
  }

  closured = false;

  static create(cores: StateItem[]) {
    const cacheKey = this.getMapKey(cores);
    const state = this.closureMap.get(cacheKey);
    if (state) return state;

    const newState = new State(cores);
    this.closureMap.set(cacheKey, newState);
    return newState;
  }

  static getMapKey(cores: StateItem[]) {
    return cores.map((item) => item.id).join(';');
  }

  private constructor(cores: StateItem[]) {
    this.id = State._id++;
    this._items = Array.from(cores);
    this.cores = Array.from(cores);
    State.pool.set(this.id, this);
  }

  addItem(item: StateItem) {
    if (this._items.findIndex((it) => it.id === item.id) !== -1) return;
    this._items.push(item);
  }
}
