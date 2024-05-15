import * as esbuild from 'esbuild';
import path from 'path';

const commonOpts: Parameters<typeof esbuild.build>[0] = {
  entryPoints: [path.join(__dirname, 'src/main.ts')],
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
      entryNames: 'shaderlab.main.browser',
    }),
    esbuild.build({
      ...commonOpts,
      format: 'esm',
      minify: true,
      entryNames: 'shaderlab.main.browser.min',
    }),
    esbuild.build({
      ...commonOpts,
      format: 'cjs',
      minify: true,
      entryNames: 'shaderlab.main.module.min',
    }),
  ]);
}

main();
