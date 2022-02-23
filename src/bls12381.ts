import type { BlsKeyPair, BlindedBlsKeyPair } from './types'

export const generateBls12381G1KeyPair = async (seed?: Uint8Array): Promise<Required<BlsKeyPair>> => {
  return new Promise<Required<BlsKeyPair>>(() => console.log(seed))
}

export const generateBlindedBls12381G1KeyPair = async (seed?: Uint8Array): Promise<Required<BlindedBlsKeyPair>> => {
  return new Promise<Required<BlindedBlsKeyPair>>(() => console.log(seed))
}

export const generateBls12381G2KeyPair = async (seed?: Uint8Array): Promise<Required<BlsKeyPair>> => {
  return new Promise<Required<BlsKeyPair>>(() => console.log(seed))
}

export const generateBlindedBls12381G2KeyPair = async (seed?: Uint8Array): Promise<Required<BlindedBlsKeyPair>> => {
  return new Promise<Required<BlindedBlsKeyPair>>(() => console.log(seed))
}
