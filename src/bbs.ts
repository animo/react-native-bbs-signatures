type SignOptions = {}
type BlsSignOptions = {}
type VerifyOptions = {}
type BlsVerifyOptions = {}
type CreateProofOptions = {}
type BlsCreateProofOptions = {}
type VerifyProofOptions = {}
type BlsVerifyProofOptions = {}
type CommitmentForBlindSignRequestOptions = {}
type VerifyBlindSignRequestOptions = {}
type BlindSignOptions = {}
// ---
type GenerateBls12381G1KeyPairOptions = {}
type GenerateBlindedBls12381G1KeyPairOptions = {}
type GenerateBls12381G2KeyPairOptions = {}
type GenerateBlindedBls12381G2KeyPairOptions = {}
// ---
type Bl12381toBbsOptions = {}

export interface Bbs {
  sign(options: SignOptions): {}
  blsSign(options: BlsSignOptions): {}
  verify(options: VerifyOptions): {}
  blsVerify(options: BlsVerifyOptions): {}
  createProof(options: CreateProofOptions): {}
  blsCreateProof(options: BlsCreateProofOptions): {}
  verifyProof(options: VerifyProofOptions): {}
  blsVerifyProof(options: BlsVerifyProofOptions): {}
  commitmentForBlindSignRequest(options: CommitmentForBlindSignRequestOptions): {}
  verifyBlindSignRequest(options: VerifyBlindSignRequestOptions): {}
  blindSign(options: BlindSignOptions): {}
  // ---
  generateBls12381G1KeyPair(options: GenerateBls12381G1KeyPairOptions): {}
  generateBlindedBls12381G1KeyPair(options: GenerateBlindedBls12381G1KeyPairOptions): {}
  generateBls12381G2KeyPair(options: GenerateBls12381G2KeyPairOptions): {}
  generateBlindedBls12381G2KeyPair(options: GenerateBlindedBls12381G2KeyPairOptions): {}
  // ---
  bl12381toBbs(options: Bl12381toBbsOptions): {}
}
