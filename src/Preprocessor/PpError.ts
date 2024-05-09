import { Logger } from '../Logger';
import Position, { LocRange } from '../common/Position';

export class PpError {
  logger = new Logger('Preprocessor');

  protected throw(pos: Position | LocRange, ...msgs: any[]): never {
    this.logger.log(Logger.RED, pos.toString(), ...msgs);
    throw msgs.join(' ');
  }
}
