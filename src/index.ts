import Lexer from './Lexer';
import Parser from './Parser';
import Preprocessor from './Preprocessor';
import { createGrammar, addTranslationRule } from './Grammar/galacean';
import LRLoader from './Parser/Loader';

export class ShaderLab {
  private parser: Parser;

  constructor(grammarBin: ArrayBuffer) {
    const grammar = createGrammar();
    this.parser = LRLoader.load(grammarBin, grammar);
    addTranslationRule(this.parser.sematicAnalyzer);
  }

  parse(source: string) {
    const preprocessor = new Preprocessor(source);
    const ppdContent = preprocessor.process();
    const lexer = new Lexer(ppdContent);
    const tokens = lexer.tokenize();
    return this.parser.parse(tokens);
  }
}
