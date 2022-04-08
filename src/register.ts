import type { Bbs } from "./bbs";
import type { BbsNativeBindings } from "./turboModule";

// TODO: how can we throw an error is this goes wrong
declare var _bbs_signatures: BbsNativeBindings;

export const bbsNativeBindings = _bbs_signatures as Bbs;
