import type { BbsNativeBindings } from './turboModule'

declare var _bbsSignatures: BbsNativeBindings

export const bbsNativeBindings = _bbsSignatures as BbsNativeBindings
