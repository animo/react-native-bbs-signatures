// General interface for the package. Our generated cpp wrapper will be based on this
export interface BbsNativeBindings {
  sign(options: {}): {};
  verify(options: {}): {};
  createProof(options: {}): {};
  verifyProof(options: {}): {};
  generateBls12381G1KeyPair(options: {}): {};
  generateBls12381G2KeyPair(options: {}): {};
  bls12381toBbs(options: {}): {};
}
