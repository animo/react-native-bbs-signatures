import type { Spec } from './turboModule'

declare var _bbsSignatures: Spec

export const turboModule = _bbsSignatures as Spec

export type TurboModuleType = Spec
