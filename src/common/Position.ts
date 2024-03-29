export default class Position {
  index: number;
  line: number;
  column: number;

  constructor(index: number, line: number, column: number) {
    this.index = index;
    this.line = line;
    this.column = column;
  }
}
