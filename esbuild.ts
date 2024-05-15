import * as esbuild from 'esbuild';
import path from 'path';

const commonOpts: Parameters<typeof esbuild.build>[0] = {
  entryPoints: [path.join(__dirname, 'src/index.ts')],
  bundle: true,
  mainFields: ['browser', 'main', 'module'],
  sourcemap: true,
  outdir: 'dist',
  loader: { '.bin': 'binary' },
};

async function main() {
  await Promise.all([
    esbuild.build({
      ...commonOpts,
      format: 'esm',
      entryNames: 'shaderlab.browser',
    }),
    esbuild.build({
      ...commonOpts,
      format: 'esm',
      minify: true,
      entryNames: 'shaderlab.browser.min',
    }),
    esbuild.build({
      ...commonOpts,
      format: 'cjs',
      minify: true,
      entryNames: 'shaderlab.module.min',
    }),
  ]);
}

main();
