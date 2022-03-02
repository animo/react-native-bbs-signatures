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

// export const BBS_SIGNATURE_LENGTH = 112

// TODO: promisfy
export const sign = ({ messages, keyPair }: BbsSignRequest): Uint8Array => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { signature } = bbsNativeBindings.sign({
    publicKey: keyPair.publicKey.buffer,
    secretKey: keyPair.secretKey!.buffer,
    messages: messageBuffers,
  })

  return signature as Uint8Array
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

export const createProof = ({ publicKey, messages, signature, nonce, revealed }: BbsCreateProofRequest): Uint8Array => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { proof } = bbsNativeBindings.createProof({
    publicKey: publicKey.buffer,
    messages: messageBuffers,
    signature: signature.buffer,
    nonce: nonce.buffer,
    revealed,
  })

  return proof
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

export const blsSign = ({ messages, keyPair }: BlsBbsSignRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const blsVerify = ({ messages, publicKey, signature }: BlsBbsVerifyRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
}

// This should call createProof now.
export const blsCreateProof = ({
  signature,
  publicKey,
  messages,
  nonce,
  revealed,
}: BbsCreateProofRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}

// does NOT need to call verifyProof
export const blsVerifyProof = ({ nonce, proof, messages, publicKey }: BbsVerifyProofRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const commitmentForBlindSignRequest = ({}: BbsBlindSignContextRequest): BbsBlindSignContext => {
  throw new Error('NOT YET IMPLEMENTED')
  // const messageBuffers = messages.map((m) => m.buffer)
  // const = bbsNativeBindings.commitmentForBlindSignRequest({
  //   nonce: nonce.buffer,
  //   hidden,
  //   messages: messageBuffers,
  //   publicKey: publicKey.buffer,
  // })
}

export const verifyBlindSignContext = ({}: BbsVerifyBlindSignContextRequest): boolean => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const blindSign = (request: BbsBlindSignRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}
