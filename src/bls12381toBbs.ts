import { bbsNativeBindings } from './register'
import type { BbsKeyPair, Bls12381ToBbsRequest } from './types'

export const bls12381toBbs = (request: Bls12381ToBbsRequest): BbsKeyPair => {
  const { publicKey } = bbsNativeBindings.bls12381toBbs({
    publicKey: request.keyPair.publicKey.buffer,
    messageCount: request.messageCount,
  })

  return {
    publicKey: new Uint8Array(publicKey),
    secretKey: request.keyPair.secretKey,
    messageCount: request.messageCount,
  }
}
