import PpParser from './Parser';
import PpScanner from './Scanner';

export default class Preprocessor {
  private scanner: PpScanner;
  private parser: PpParser;

  constructor(source: string) {
    this.scanner = new PpScanner(source);
    this.parser = new PpParser();
  }

  process() {
    return this.parser.parse(this.scanner);
  }
}

export { Preprocessor };
