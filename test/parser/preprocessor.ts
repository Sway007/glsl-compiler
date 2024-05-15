import { readFileSync, writeFileSync } from 'fs';
import { join } from 'path';
import Preprocessor from '../../src/Preprocessor';

const filePath = join(__dirname, '/cases/pp/pbr_frag.txt');
const demoContent = readFileSync(filePath).toString();

const preprocessor = new Preprocessor(demoContent);
const expanded = preprocessor.process();
const outputPath = join(__dirname, 'output/expanded.txt');
writeFileSync(outputPath, expanded);
console.log(preprocessor);
console.log('done');
