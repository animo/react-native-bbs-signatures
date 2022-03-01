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

// TODO: promisfy
export const sign = (request: BbsSignRequest): Uint8Array => {
  const messageBuffers = request.messages.map((m) => m.buffer)
  const x = bbsNativeBindings.sign({publicKey: request.keyPair.publicKey.buffer, secretKey: request.keyPair.secretKey!.buffer, messages: messageBuffers});
  console.log(x)
  return new Uint8Array([0])
}

// This should call sign now.
export const blsSign = (request: BlsBbsSignRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const verify = (request: BbsVerifyRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call verify now.
export const blsVerify = (request: BlsBbsVerifyRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const createProof = (request: BbsCreateProofRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call createProof now.
export const blsCreateProof = (request: BbsCreateProofRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const verifyProof = (request: BbsVerifyProofRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call verifyProof now.
// does NOT need to call verifyProof
export const blsVerifyProof = (request: BbsVerifyProofRequest): BbsVerifyResult => {
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
  throw new Error('NOT YET IMPLEMENTED')
}
