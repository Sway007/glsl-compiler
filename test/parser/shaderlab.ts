import { readFileSync } from 'fs';
import { join } from 'path';
import { ShaderLab } from '../../src';

async function main() {
  const source = readFileSync(
    join(__dirname, 'cases/glsl/demo2.gs')
  ).toString();

  const buffer = readFileSync('lalr1.bin');
  const arraybuffer = new ArrayBuffer(buffer.byteLength);
  const view = new DataView(arraybuffer);
  for (let i = 0; i < buffer.byteLength; i++) {
    view.setUint8(i, buffer[i]);
  }

  const shaderLab = new ShaderLab(arraybuffer);

  const start = performance.now();
  const ret = shaderLab.parse(source);
  console.log(`time cost: ${(performance.now() - start).toFixed(2)}ms.`);
  console.log(ret);
}

main();
