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
export const sign = ({ messages, keyPair }: BbsSignRequest): Uint8Array => {
  const messageBuffers = messages.map((m) => m.buffer)
  const { signature } = bbsNativeBindings.sign({
    publicKey: keyPair.publicKey.buffer,
    secretKey: keyPair.secretKey!.buffer,
    messages: messageBuffers,
  })

  console.log(signature)
  return signature as Uint8Array
}

// This should call sign now.
export const blsSign = (request: BlsBbsSignRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
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

// This should call verify now.
export const blsVerify = (request: BlsBbsVerifyRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
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

// This should call createProof now.
export const blsCreateProof = (request: BbsCreateProofRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
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

// This should call verifyProof now.
// does NOT need to call verifyProof
export const blsVerifyProof = (request: BbsVerifyProofRequest): BbsVerifyResult => {
  throw new Error('NOT YET IMPLEMENTED')
}

export const commitmentForBlindSignRequest = ({
  nonce,
  hidden,
  messages,
  publicKey,
}: BbsBlindSignContextRequest): BbsBlindSignContext => {
  const messageBuffers = messages.map((m) => m.buffer)
  const x = bbsNativeBindings.commitmentForBlindSignRequest({
    nonce: nonce.buffer,
    hidden,
    messages: messageBuffers,
    publicKey: publicKey.buffer,
  })

  console.log(JSON.stringify(x))

  throw new Error('DONT KNOW HOW TO DEAL WITH THIS RETURN TYPE')
}

export const verifyBlindSignContext = ({
  publicKey,
  nonce,
  blinded,
  commitment,
  challengeHash,
  proofOfHiddenMessages,
}: BbsVerifyBlindSignContextRequest): boolean => {
  const c = bbsNativeBindings.verifyBlindSignRequest({
    nonce: nonce.buffer,
    blinded,
    publicKey: publicKey.buffer,
    commitment: commitment.buffer,
    challengeHash: challengeHash.buffer,
    proofOfHiddenMessages: proofOfHiddenMessages.buffer,
  })
  console.log(JSON.stringify(c))
  throw new Error('NOT YET IMPLEMENTED')
}

export const blindSign = (request: BbsBlindSignRequest): Uint8Array => {
  throw new Error('NOT YET IMPLEMENTED')
}
