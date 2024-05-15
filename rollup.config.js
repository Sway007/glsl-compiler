const path = require('path');
const { minify, swc } = require('rollup-plugin-swc3');
const { string } = require('rollup-plugin-string');

const commonOpts = {
  input: path.join(__dirname, 'src/index.ts'),
  output: {
    dir: 'dist',
    name: 'ShaderLab',
  },
  plugins: [swc(), string({ include: '**/*.bin' })],
};

exports.default = [
  {
    ...commonOpts,
    output: {
      ...commonOpts.output,
      format: 'umd',
      entryFileNames: 'module.rollup.js',
    },
  },
  {
    ...commonOpts,
    output: {
      ...commonOpts.output,
      format: 'umd',
      entryFileNames: 'module.rollup.min.js',
    },
    plugins: commonOpts.plugins.concat([minify()]),
  },
  {
    ...commonOpts,
    output: {
      ...commonOpts.output,
      format: 'es',
      entryFileNames: 'browser.rollup.js',
    },
  },
  // {
  //   ...commonOpts,
  //   output: {
  //     ...commonOpts.output,
  //     format: 'es',
  //     entryFileNames: 'browser.rollup.min.js',
  //   },
  //   plugins: commonOpts.plugins.concat([minify({ sourceMap: true })]),
  // },
];
