import { bbsNativeBindings } from './register'
import type { BlsKeyPair, BlindedBlsKeyPair } from './types'

export const generateBls12381G1KeyPair = (seed?: Uint8Array): Required<BlsKeyPair> => {
  const { publicKey, secretKey } = bbsNativeBindings.generateBls12381G1KeyPair({ seed: seed?.buffer })
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
  }
}

export const generateBlindedBls12381G1KeyPair = (seed?: Uint8Array): Required<BlindedBlsKeyPair> => {
  const { publicKey, secretKey, blindingFactor } = bbsNativeBindings.generateBlindedBls12381G1KeyPair({
    seed: seed?.buffer,
  })
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
    blindingFactor: new Uint8Array(blindingFactor),
  }
}

export const generateBls12381G2KeyPair = (seed?: Uint8Array): Required<BlsKeyPair> => {
  const { publicKey, secretKey } = bbsNativeBindings.generateBls12381G2KeyPair({ seed: seed?.buffer })
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
  }
}

export const generateBlindedBls12381G2KeyPair = (seed?: Uint8Array): Required<BlindedBlsKeyPair> => {
  const { publicKey, secretKey, blindingFactor } = bbsNativeBindings.generateBlindedBls12381G2KeyPair({
    seed: seed?.buffer,
  })
  return {
    secretKey: new Uint8Array(secretKey),
    publicKey: new Uint8Array(publicKey),
    blindingFactor: new Uint8Array(blindingFactor),
  }
}
