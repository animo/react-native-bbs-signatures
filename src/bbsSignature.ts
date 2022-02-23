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

export const sign = async (request: BbsSignRequest): Promise<Uint8Array> => {
  return new Promise<Uint8Array>(() => console.log(request))
}

export const blsSign = async (request: BlsBbsSignRequest): Promise<Uint8Array> => {
  return new Promise<Uint8Array>(() => console.log(request))
}

export const verify = async (request: BbsVerifyRequest): Promise<BbsVerifyResult> => {
  return new Promise<BbsVerifyResult>(() => console.log(request))
}

export const blsVerify = async (request: BlsBbsVerifyRequest): Promise<BbsVerifyResult> => {
  return new Promise<BbsVerifyResult>(() => console.log(request))
}

export const createProof = async (request: BbsCreateProofRequest): Promise<Uint8Array> => {
  return new Promise<Uint8Array>(() => console.log(request))
}

export const blsCreateProof = async (request: BbsCreateProofRequest): Promise<Uint8Array> => {
  return new Promise<Uint8Array>(() => console.log(request))
}

export const verifyProof = async (request: BbsVerifyProofRequest): Promise<BbsVerifyResult> => {
  return new Promise<BbsVerifyResult>(() => console.log(request))
}

export const blsVerifyProof = async (request: BbsVerifyProofRequest): Promise<BbsVerifyResult> => {
  return new Promise<BbsVerifyResult>(() => console.log(request))
}

export const commitmentForBlindSignRequest = async (
  request: BbsBlindSignContextRequest
): Promise<BbsBlindSignContext> => {
  return new Promise<BbsBlindSignContext>(() => console.log(request))
}

export const verifyBlindSignContext = async (request: BbsVerifyBlindSignContextRequest): Promise<boolean> => {
  return new Promise<boolean>(() => console.log(request))
}

export const blindSign = async (request: BbsBlindSignRequest): Promise<Uint8Array> => {
  return new Promise<Uint8Array>(() => console.log(request))
}
