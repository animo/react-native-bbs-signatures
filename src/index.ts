import { NativeModules } from "react-native";

export * from "./types";
export {
  generateBls12381G1KeyPair,
  generateBls12381G2KeyPair,
} from "./bls12381";
export { bls12381toBbs } from "./bls12381toBbs";
export {
  sign,
  blsSign,
  verify,
  blsVerify,
  createProof,
  blsCreateProof,
  verifyProof,
  blsVerifyProof,
} from "./bbsSignature";

const module = NativeModules.BbsSignatures;
const res = module.install();
if (!res) {
  throw new Error("nope...");
}
