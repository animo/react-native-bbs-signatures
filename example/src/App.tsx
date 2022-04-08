import * as React from "react";
import { StyleSheet, Text, View, Button } from "react-native";
import {
  bls12381toBbs,
  blsCreateProof,
  blsSign,
  blsVerify,
  blsVerifyProof,
  createProof,
  generateBls12381G2KeyPair,
  ProofMessageType,
  sign,
  verify,
  verifyProof,
} from "@animo-id/react-native-bbs-signatures";

const mockMessages = [new Uint8Array([1, 2, 3, 4])];
const mockNonce = new Uint8Array([1, 2, 3]);
const mockRevealed = [ProofMessageType.Revealed];
//const mockHidden = [0]

export default function App() {
  const [isBlsSignatureVerified, setIsBlsSignatureVerified] =
    React.useState(false);
  const [isBlsProofVerified, setIsBlsProofVerified] = React.useState(false);
  const [isSignatureVerified, setIsSignatureVerified] = React.useState(false);
  const [isProofVerified, setIsProofVerified] = React.useState(false);
  const flow = async () => {
    const blsKeyPair = await generateBls12381G2KeyPair();

    const blsSignature = await blsSign({
      keyPair: blsKeyPair,
      messages: mockMessages,
    });

    const blsVerified = await blsVerify({
      publicKey: blsKeyPair.publicKey,
      messages: mockMessages,
      signature: blsSignature,
    });

    setIsBlsSignatureVerified(blsVerified);

    const blsProof = await blsCreateProof({
      signature: blsSignature,
      publicKey: blsKeyPair.publicKey,
      messages: mockMessages,
      revealed: mockRevealed,
      nonce: mockNonce,
    });

    const blsVerifiedProof = (
      await blsVerifyProof({
        nonce: mockNonce,
        proof: blsProof,
        publicKey: blsKeyPair.publicKey,
        messages: mockMessages,
      })
    ).verified;

    setIsBlsProofVerified(blsVerifiedProof);

    const bbsKeyPair = await bls12381toBbs({
      keyPair: blsKeyPair,
      messageCount: mockMessages.length,
    });

    const signature = await sign({
      keyPair: bbsKeyPair,
      messages: mockMessages,
    });

    const verified = (
      await verify({
        signature,
        messages: mockMessages,
        publicKey: bbsKeyPair.publicKey,
      })
    ).verified;

    setIsSignatureVerified(verified);

    const proof = await createProof({
      publicKey: bbsKeyPair.publicKey,
      messages: mockMessages,
      signature,
      nonce: mockNonce,
      revealed: mockRevealed,
    });

    const verifiedProof = (
      await verifyProof({
        nonce: mockNonce,
        messages: mockMessages,
        publicKey: bbsKeyPair.publicKey,
        proof,
      })
    ).verified;

    setIsProofVerified(verifiedProof);
  };

  return (
    <View style={styles.container}>
      <Button onPress={flow} title="flow" />
      <Text style={isBlsSignatureVerified ? styles.green : styles.red}>
        bls Signature
      </Text>
      <Text style={isBlsProofVerified ? styles.green : styles.red}>
        bls Proof
      </Text>
      <Text style={isSignatureVerified ? styles.green : styles.red}>
        Signature
      </Text>
      <Text style={isProofVerified ? styles.green : styles.red}>Proof</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
  },
  green: {
    color: "#00ff00",
  },
  red: {
    color: "#ff0000",
  },
});
