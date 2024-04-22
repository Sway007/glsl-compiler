import { createWriteStream, readFileSync } from 'fs';
import Grammar from '../../src/Grammar';
import { ENonTerminal } from '../../src/Grammar/GrammarSymbol';
import { EKeyword, ETokenType } from '../../src/Lexer/TokenType';
import LREncoder from '../../src/ParserGenerator/Encoder';
import LALR1 from '../../src/ParserGenerator/LALR1';
import LRLoader from '../../src/Parser/Loader';
import { printFirstSet, printStatePool, printStateTable } from './utils';
import Lexer from '../../src/Lexer';
// import testCase from './cases/arithmetic';
// import testCase from './cases/circle';
// import testCase from './cases/typeCheck';
// import testCase from './cases/simple';
// import testCase from './cases/medium';
// import testCase from './cases/glsl';
import testCase from './cases/galacean';

async function main() {
  const grammar = testCase.createGrammar();

  const parser = new LALR1(grammar);
  parser.generate();

  // await printFirstSet(parser.firstSetMap, '.local/firstSet.text');
  // await printStatePool('.local/state.txt');
  if (testCase.printConfig) printStateTable(testCase.printConfig, parser);
  LREncoder.encode('lalr1.bin', parser);

  console.log('decoding ....');
  const buffer = readFileSync('lalr1.bin');
  const arraybuffer = new ArrayBuffer(buffer.byteLength);
  const view = new DataView(arraybuffer);
  for (let i = 0; i < buffer.byteLength; i++) {
    view.setUint8(i, buffer[i]);
  }

  const decodedParser = LRLoader.load(arraybuffer, grammar);
  // if (testCase.printConfig)
  //   printStateTable(testCase.printConfig, decodedParser);

  const lexer = new Lexer(testCase.source);
  const tokens = lexer.tokenize();
  testCase.addTranslationRule(decodedParser.sematicAnalyzer);
  decodedParser.parse(tokens);
}

main();
