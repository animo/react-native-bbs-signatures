import { bbsNativeBindings } from "./register";
import type { BbsKeyPair, Bls12381ToBbsRequest } from "./types";

/**
 * Converts a BLS12-381 key to a BBS+ key
 * @param request Request for the key conversion
 *
 * @returns A BbsKeyPair
 */
export const bls12381toBbs = async (
  request: Bls12381ToBbsRequest
): Promise<BbsKeyPair> => {
  try {
    const { publicKey } = bbsNativeBindings.bls12381toBbs({
      publicKey: request.keyPair.publicKey.buffer,
      messageCount: request.messageCount,
    });

    return {
      publicKey: new Uint8Array(publicKey),
      secretKey: request.keyPair.secretKey,
      messageCount: request.messageCount,
    };
  } catch {
    throw new Error("Failed to convert key");
  }
};
