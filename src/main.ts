import Lexer from './Lexer';
import Parser from './Parser';
import Preprocessor from './Preprocessor';
import { createGrammar, addTranslationRule } from './Grammar/galacean';
import { GLES100Visitor, GLES300Visitor } from './CodeGen';

import LALR1 from './ParserGenerator/LALR1';

export enum EBackend {
  GLES100,
  GLES300,
}

export class ShaderLab {
  private parser: Parser;

  constructor() {
    const grammar = createGrammar();
    const generator = new LALR1(grammar);
    this.parser = generator.generate();
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
