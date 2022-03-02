import { bbsNativeBindings } from './register'
import type { BbsKeyPair, Bls12381ToBbsRequest } from './types'

export const bls12381toBbs = (request: Bls12381ToBbsRequest): BbsKeyPair => {
  const { publicKey } = bbsNativeBindings.bls12381toBbs({
    messageCount: request.messageCount,
    publicKey: request.keyPair.publicKey.buffer,
  })

  return {
    publicKey: publicKey,
    secretKey: request.keyPair.secretKey,
    messageCount: request.messageCount,
  }
}
