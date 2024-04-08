export default class Position {
  index: number;
  line: number;
  column: number;

  constructor(index: number, line: number, column: number) {
    this.index = index;
    this.line = line;
    this.column = column;
  }

  /** @returns new position with offset */
  offset(count: number) {
    return new Position(this.index + count, this.line, this.column + count);
  }
}

export class LocRange {
  readonly start: Position;
  readonly end: Position;

  constructor(start: Position, end: Position) {
    this.start = start;
    this.end = end;
  }

  toString() {
    return `Loc<start: line ${this.start.line}, column ${this.start.column}; end: line ${this.end.line}, column ${this.end.column}>`;
  }
}
