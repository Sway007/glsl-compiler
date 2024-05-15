import { ExpandSegment } from './Parser';

export class PpUtils {
  static expand(segments: ExpandSegment[], source: string) {
    const ret: string[] = [];
    let startIdx = 0;
    for (const seg of segments) {
      const originSlice = source.slice(startIdx, seg.range.start.index);
      ret.push(originSlice, seg.replace);
      startIdx = seg.range.end.index;
    }
    ret.push(source.slice(startIdx));
    return ret.join('');
  }
}
