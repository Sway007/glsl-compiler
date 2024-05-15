import Lexer from './Lexer';
import Parser from './Parser';
import Preprocessor from './Preprocessor';
import { createGrammar, addTranslationRule } from './Grammar/galacean';
import LRLoader from './Parser/Loader';
import { GLES100Visitor, GLES300Visitor } from './CodeGen';

import grammarData from './lalr1.bin';

export enum EBackend {
  GLES100,
  GLES300,
}

export class ShaderLab {
  private parser: Parser;

  constructor() {
    const grammar = createGrammar();
    this.parser = LRLoader.load(grammarData.buffer, grammar);
    addTranslationRule(this.parser.sematicAnalyzer);
  }

  parse(source: string, backend = EBackend.GLES300) {
    const preprocessor = new Preprocessor(source);
    const ppdContent = preprocessor.process();
    const lexer = new Lexer(ppdContent);
    const tokens = lexer.tokenize();
    const program = this.parser.parse(tokens);
    const codeGen =
      backend === EBackend.GLES100
        ? new GLES100Visitor()
        : new GLES300Visitor();
    return codeGen.visitShaderProgram(program);
  }
}
