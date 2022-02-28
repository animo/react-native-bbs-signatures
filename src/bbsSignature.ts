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

export const BBS_SIGNATURE_LENGTH = 112

// This is probably a builder that handles the whole process
// Which steps do we havr to do here
// export const sign = (request: BbsSignRequest): Uint8Array => {
export const sign = (request: BbsSignRequest): Uint8Array => {
  const { keyPair, messages } = request

  if (!keyPair.secretKey) throw new Error('Secret key must be set')

  const messageBuffers = messages.map((m) => m.buffer)
  const handle = bbsNativeBindings.bbs_sign_context_init()

  messageBuffers.forEach((message) =>
    bbsNativeBindings.bbs_sign_context_add_message_string({ handle, message: 'Hello' })
  )

  //bbsNativeBindings.bbs_sign_context_set_public_key({ handle, publicKey: keyPair.publicKey.buffer })
  //// TODO: handle undefined?
  //bbsNativeBindings.bbs_sign_context_set_secret_key({ handle, secretKey: keyPair.secretKey.buffer })
  //const { signature } = bbsNativeBindings.bbs_sign_context_finish({ handle })
  //return signature
  return new Uint8Array([0])
}

// This should call sign now.
export const blsSign = (request: BlsBbsSignRequest): Uint8Array => {
  const { keyPair, messages } = request
  const bbsKeyPair = bls12381toBbs({ keyPair, messageCount: messages.length })
  throw new Error('NOT YET IMPLEMENTED')
}

export const verify = (request: BbsVerifyRequest): BbsVerifyResult => {
  const { publicKey, signature, messages } = request
  const messageBuffers = messages.map((m) => m.buffer)
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call verify now.
export const blsVerify = (request: BlsBbsVerifyRequest): BbsVerifyResult => {
  const { publicKey, signature, messages } = request
  const bbsKeyPair = bls12381toBbs({ keyPair, messageCount: messages.length })
  throw new Error('NOT YET IMPLEMENTED')
}

export const createProof = (request: BbsCreateProofRequest): Uint8Array => {
  const { publicKey, signature, messages, nonce, revealed } = request
  const messageBuffers = messages.map((m) => m.buffer)
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call createProof now.
export const blsCreateProof = (request: BbsCreateProofRequest): Uint8Array => {
  const { publicKey, signature, messages, nonce, revealed } = request
  const bbsKeyPair = bls12381toBbs({ keyPair: { publicKey }, messageCount: messages.length })
  throw new Error('NOT YET IMPLEMENTED')
}

export const verifyProof = (request: BbsVerifyProofRequest): BbsVerifyResult => {
  const { publicKey, proof, messages, nonce } = request
  const messageBuffers = messages.map((m) => m.buffer)
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call verifyProof now.
// does NOT need to call verifyProof
export const blsVerifyProof = (request: BbsVerifyProofRequest): BbsVerifyResult => {
  const { publicKey, proof, messages, nonce } = request
  const messageBuffers = messages.map((m) => m.buffer)
  throw new Error('NOT YET IMPLEMENTED')
}

export const commitmentForBlindSignRequest = (request: BbsBlindSignContextRequest): BbsBlindSignContext => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const verifyBlindSignContext = (request: BbsVerifyBlindSignContextRequest): boolean => {
  const { commitment, proofOfHiddenMessages, challengeHash, publicKey, blinded, nonce } = request
  throw new Error('NOT YET IMPLEMENTED')
}

export const blindSign = (request: BbsBlindSignRequest): Uint8Array => {
  const { commitment, secretKey, messages } = request
  const messageBuffers = messages.map((m) => m.buffer)
  throw new Error('NOT YET IMPLEMENTED')
}
