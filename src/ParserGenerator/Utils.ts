import Production from '../Grammar/Production';
import State from '../Grammar/State';
import { ActionInfo, EAction } from './common';

export default class Utils {
  static addMapSetItem<K, T>(map: Map<K, Set<T>>, k: K, v: T) {
    const set = map.get(k) ?? new Set();
    set.add(v);
    map.set(k, set);
  }

  static isSubSet<T>(sa: Set<T>, sb: Set<T>) {
    for (const item of sa) {
      if (!sb.has(item)) return false;
    }
    return true;
  }

  static isActionEqual(a: ActionInfo, b: ActionInfo) {
    return a.action === b.action && a.target === b.target;
  }

  static printAction(actionInfo: ActionInfo) {
    return `<Action: ${EAction[actionInfo.action]} -> ${
      actionInfo.action === EAction.Reduce
        ? Production.pool.get(actionInfo.target!)
        : `State ${actionInfo.target!}`
    }>`;
  }
}
