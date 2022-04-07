import type { BbsNativeBindings } from "./turboModule";
import type { Bbs } from "./bbs";

declare var _bbs_signatures: BbsNativeBindings;

export const bbsNativeBindings = _bbs_signatures as Bbs;
