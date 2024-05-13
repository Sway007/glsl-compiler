import { mkdirSync, readFileSync, writeFileSync } from 'fs';
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
import { createGrammar, addTranslationRule } from '../../src/Grammar/galacean';
import { GLES100Visitor, GLES300Visitor } from '../../src/CodeGen';
import { join } from 'path';

async function main() {
  const grammar = createGrammar();

  const source = readFileSync(
    join(__dirname, 'cases/glsl/demo2.gs')
  ).toString();

  const parser = new LALR1(grammar);
  parser.generate();

  await printFirstSet(parser.firstSetMap, '.local/firstSet.text');
  await printStatePool('.local/state.txt');
  // if (testCase.printConfig) printStateTable(testCase.printConfig, parser);
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

  const lexer = new Lexer(source);
  const tokens = lexer.tokenize();
  addTranslationRule(decodedParser.sematicAnalyzer);
  // decodedParser.parse(tokens, true);
  const ret = decodedParser.parse(tokens);
  const codeGen = new GLES300Visitor();
  const result = codeGen.visitShaderProgram(ret);
  writeOutput(result);

  console.log('done');
}

function writeOutput(shaderOutput: IShaderCodeGenResult) {
  const outputDirRoot = join(__dirname, 'output', shaderOutput.name);
  for (const subShader of shaderOutput.subShaderList) {
    const outputDir = join(outputDirRoot, subShader.name);
    for (const pass of subShader.passList) {
      const output = join(outputDir, pass.name);
      mkdirSync(output, { recursive: true });
      const vertFile = join(output, `${pass.name}.vert`);
      writeFileSync(vertFile, pass.vertexSource);
      const fragFile = join(output, `${pass.name}.frag`);
      writeFileSync(fragFile, pass.fragmentSource);
    }
  }
}

main();
