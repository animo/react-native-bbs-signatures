import { bbsNativeBindings } from './register'
import type { BlsKeyPair, BlindedBlsKeyPair } from './types'

export const generateBls12381G1KeyPair = (seed?: Uint8Array): Required<BlsKeyPair> => bbsNativeBindings.generateBls12381G1KeyPair({seed}) 

export const generateBlindedBls12381G1KeyPair = (seed?: Uint8Array): Required<BlindedBlsKeyPair> => {
  return bbsNativeBindings.bls_generate_blinded_g1_key({ seed })
}

export const generateBls12381G2KeyPair = (seed?: Uint8Array): Required<BlsKeyPair> => {
  return bbsNativeBindings.bls_generate_g2_key({ seed })
}

export const generateBlindedBls12381G2KeyPair = (seed?: Uint8Array): Required<BlindedBlsKeyPair> => {
  return bbsNativeBindings.bls_generate_blinded_g2_key({ seed })
}
