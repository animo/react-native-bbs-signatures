import { bls12381toBbs } from './bls12381toBbs'
import { bbsNativeBindings } from './register'
import type {
  BbsBlindSignContext,
  BbsBlindSignContextRequest,
  BbsBlindSignRequest,
  BbsCreateProofRequest,
  BbsSignRequest,
  BbsVerifyBlindSignContextRequest,
  BbsVerifyProofRequest,
  BbsVerifyRequest,
  BbsVerifyResult,
  BlsBbsSignRequest,
  BlsBbsVerifyRequest,
} from './types'

// TODO: promisfy
export const sign = ({ messages, keyPair }: BbsSignRequest): Uint8Array => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { signature } = bbsNativeBindings.sign({
    publicKey: keyPair.publicKey.buffer,
    secretKey: keyPair.secretKey!.buffer,
    messages: messageBuffers,
  })

  return new Uint8Array(signature)
}

export const blsSign = ({ messages, keyPair }: BlsBbsSignRequest): Uint8Array => {
  const bbsKeyPair = bls12381toBbs({ keyPair, messageCount: messages.length })
  return sign({ keyPair: bbsKeyPair, messages })
}

export const verify = ({ publicKey, signature, messages }: BbsVerifyRequest): BbsVerifyResult => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { verified } = bbsNativeBindings.verify({
    publicKey: publicKey.buffer,
    signature: signature.buffer,
    messages: messageBuffers,
  })

  // TODO: What does the node error string contain
  return {
    verified,
  }
}

export const blsVerify = ({ messages, publicKey, signature }: BlsBbsVerifyRequest): BbsVerifyResult => {
  const bbsKeyPair = bls12381toBbs({ keyPair: { publicKey }, messageCount: messages.length })
  return verify({ messages, signature, publicKey: bbsKeyPair.publicKey })
}

export const createProof = ({ publicKey, messages, signature, nonce, revealed }: BbsCreateProofRequest): Uint8Array => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { proof } = bbsNativeBindings.createProof({
    publicKey: publicKey.buffer,
    messages: messageBuffers,
    signature: signature.buffer,
    nonce: nonce.buffer,
    revealed,
  })

  return new Uint8Array(proof)
}

export const blsCreateProof = ({
  signature,
  publicKey,
  messages,
  nonce,
  revealed,
}: BbsCreateProofRequest): Uint8Array => {
  const bbsKeyPair = bls12381toBbs({ keyPair: { publicKey }, messageCount: messages.length })
  return createProof({ publicKey: bbsKeyPair.publicKey, signature, messages, nonce, revealed })
}

export const verifyProof = ({ nonce, proof, messages, publicKey }: BbsVerifyProofRequest): BbsVerifyResult => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { verified } = bbsNativeBindings.verifyProof({
    publicKey: publicKey.buffer,
    messages: messageBuffers,
    proof: proof.buffer,
    nonce: nonce.buffer,
  })

  return {
    verified,
  }
}

export const blsVerifyProof = ({ nonce, proof, messages, publicKey }: BbsVerifyProofRequest): BbsVerifyResult => {
  const bbsKeyPair = bls12381toBbs({ keyPair: { publicKey }, messageCount: messages.length })
  return verifyProof({ publicKey: bbsKeyPair.publicKey, nonce, messages, proof })
}

export const commitmentForBlindSignRequest = ({}: BbsBlindSignContextRequest): BbsBlindSignContext => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const verifyBlindSignContext = ({}: BbsVerifyBlindSignContextRequest): boolean => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const blindSign = ({}: BbsBlindSignRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}
