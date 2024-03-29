import { Derivation } from './Symbol';

export default class ParserUtils {
  static equalDerivation(d1: Derivation, d2: Derivation) {
    if (d1.length !== d2.length) return false;
    for (let i = 0; i < d1.length; i++) {
      if (d1[i].id !== d2[i].id) return false;
    }
    return true;
  }

  static addMapArrayItem<K, V>(map: Map<K, Array<V>>, k: K, v: V) {
    const list = map.get(k) ?? [];
    list.push(v);
    map.set(k, list);
  }
}
