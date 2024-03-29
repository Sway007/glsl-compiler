import Lexer from './src/Lexer';

const source = `//test comments
float v = .8832 > 233 ? 100 : -1;
for (int i = 0; i < 100; i++) {
  function(arg1, arg2);
}
`;

const lexer = new Lexer(source);
let t = performance.now();
lexer.tokenize();
t = performance.now() - t;
console.log(t.toFixed(4));
