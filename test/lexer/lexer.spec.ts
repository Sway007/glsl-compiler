import Lexer from '../../src/Lexer';
import fs from 'fs';
import path from 'path';
import assert from 'assert';

function lexContent(fp: string) {
  const content = fs.readFileSync(path.join(__dirname, fp)).toString();
  const lexer = new Lexer(content);
  let t = performance.now();
  lexer.tokenize();
  console.log('time:', (performance.now() - t).toFixed(4));
}

describe('Lexer', () => {
  it('case1', () => {
    lexContent('case1.txt');
  });

  it('case2', () => {
    lexContent('case2.txt');
  });

  it('case3', () => {
    lexContent('case3.txt');
  });

  it('case4', () => {
    lexContent('case4.txt');
  });
});
