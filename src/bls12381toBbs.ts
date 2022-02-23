import type { BbsKeyPair, Bls12381ToBbsRequest } from './types'

export const bls12381toBbs = async (request: Bls12381ToBbsRequest): Promise<BbsKeyPair> => {
  return new Promise<BbsKeyPair>(() => console.log(request))
}
