import type { Bbs } from "./bbs";
import type { BbsNativeBindings } from "./turboModule";

// @ts-ignore
if (!global._bbs_signatures) {
  throw Error(
    "_bbs_signatures has not been exposed on global. Something went wrong while installing the turboModule"
  );
}

declare var _bbs_signatures: BbsNativeBindings;

export const bbsNativeBindings = _bbs_signatures as Bbs;
