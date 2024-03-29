export default class GSymbol {
  private static _id = 0;
  static pool: Map<string, GSymbol> = new Map();

  nonTerminal: boolean;
  text: string;
  id: number;

  static create(text: string, nonTerminal: boolean) {
    let sm = this.pool.get(text)!;
    if (sm) return sm;

    sm = new GSymbol(text, nonTerminal);
    GSymbol.pool.set(text, sm);
    return sm;
  }

  static get terminals() {
    const ret: GSymbol[] = [];
    for (const sm of this.pool.values()) {
      if (!sm.nonTerminal) ret.push(sm);
    }
    return ret;
  }

  static get nonTerminals() {
    const ret: GSymbol[] = [];
    for (const sm of this.pool.values()) {
      if (sm.nonTerminal) ret.push(sm);
    }
    return ret;
  }

  private constructor(text: string, nonTerminal: boolean) {
    this.text = text;
    this.nonTerminal = nonTerminal;
    this.id = GSymbol._id++;
  }

  toString() {
    return `<Symbol ${this.text}>`;
  }
}

export type Derivation = GSymbol[];

export const eof = GSymbol.create('$', false);
