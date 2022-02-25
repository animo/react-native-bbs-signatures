import type { Bbs } from './bbs'

declare var _bbsSignatures: Bbs

export const bbsNativeBindings = _bbsSignatures as Bbs
