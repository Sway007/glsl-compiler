import { readFileSync } from 'fs';
import { join } from 'path';
import Preprocessor from '../../src/Preprocessor';

const filePath = join(__dirname, '/cases/pp/demo1.txt');
const demoContent = readFileSync(filePath).toString();

const preprocessor = new Preprocessor(demoContent);
preprocessor.process();
console.log(preprocessor);
console.log('done');
