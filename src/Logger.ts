export class Logger {
  readonly name: string;
  constructor(name: string) {
    this.name = name;
  }

  log(color: number, ...param: any[]) {
    console.log(`\x1B[38;5;${color}m[${this.name}]`, ...param, '\x1B[m');
  }

  static RED = 1;
  static GREEN = 41;
}
