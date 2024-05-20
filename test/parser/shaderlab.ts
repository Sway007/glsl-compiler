import { mkdirSync, readFileSync, writeFileSync } from 'fs';
import { join } from 'path';
import { ShaderLab } from '../../src/main';

const outputRoot = join(__dirname, 'output');

async function main() {
  const source = readFileSync(join(__dirname, 'cases/glsl/demo.gs')).toString();
  const shaderLab = new ShaderLab();

  const start = performance.now();
  const result = shaderLab.parse(source);
  console.log('time cost:', (performance.now() - start).toFixed(2), 'ms');
  writeOutput(result);

  console.log('done');
}

function writeOutput(shaderOutput: IShaderCodeGenResult) {
  const outputDirRoot = join(outputRoot, shaderOutput.name);
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
