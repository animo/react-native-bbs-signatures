import { bbsNativeBindings } from './register'
import type { BlsKeyPair, BlindedBlsKeyPair } from './types'

export const generateBls12381G1KeyPair = (seed?: Uint8Array): Required<BlsKeyPair> =>
  bbsNativeBindings.generateBls12381G1KeyPair({ seed })

export const generateBlindedBls12381G1KeyPair = (seed?: Uint8Array): Required<BlindedBlsKeyPair> =>
  bbsNativeBindings.generateBlindedBls12381G1KeyPair({ seed })

export const generateBls12381G2KeyPair = (seed?: Uint8Array): Required<BlsKeyPair> =>
  bbsNativeBindings.generateBls12381G2KeyPair({ seed })

export const generateBlindedBls12381G2KeyPair = (seed?: Uint8Array): Required<BlindedBlsKeyPair> =>
  bbsNativeBindings.generateBlindedBls12381G2KeyPair({ seed })
