import * as React from 'react'
import { StyleSheet, Text, View, Button } from 'react-native'
import {
  generateBls12381G2KeyPair,
  sign,
  blsSign,
  verify,
  blsVerify,
  bls12381toBbs,
  createProof,
  ProofMessageType,
  verifyProof,
  blsCreateProof,
  blsVerifyProof,
} from 'react-native-bbs-signatures'

const mockMessages = [new Uint8Array([1, 2, 3, 4])]
const mockNonce = new Uint8Array([1, 2, 3])
const mockRevealed = [ProofMessageType.Revealed]
//const mockHidden = [0]

export default function App() {
  const [isBlsSignatureVerified, setIsBlsSignatureVerified] = React.useState(false)
  const [isBlsProofVerified, setIsBlsProofVerified] = React.useState(false)
  const [isSignatureVerified, setIsSignatureVerified] = React.useState(false)
  const [isProofVerified, setIsProofVerified] = React.useState(false)
  const flow = () => {
    const blsKeyPair = generateBls12381G2KeyPair()

    const blsSignature = blsSign({ keyPair: blsKeyPair, messages: mockMessages })

    setIsBlsSignatureVerified(
      blsVerify({
        publicKey: blsKeyPair.publicKey,
        messages: mockMessages,
        signature: blsSignature,
      }).verified
    )

    const blsProof = blsCreateProof({
      signature: blsSignature,
      publicKey: blsKeyPair.publicKey,
      messages: mockMessages,
      revealed: mockRevealed,
      nonce: mockNonce,
    })

    setIsBlsProofVerified(
      blsVerifyProof({
        nonce: mockNonce,
        proof: blsProof,
        messages: mockMessages,
        publicKey: blsKeyPair.publicKey,
      }).verified
    )

    const bbsKeyPair = bls12381toBbs({ keyPair: blsKeyPair, messageCount: mockMessages.length })

    const signature = sign({ keyPair: bbsKeyPair, messages: mockMessages })

    setIsSignatureVerified(verify({ signature, messages: mockMessages, publicKey: bbsKeyPair.publicKey }).verified)

    const proof = createProof({
      publicKey: bbsKeyPair.publicKey,
      messages: mockMessages,
      signature,
      nonce: mockNonce,
      revealed: mockRevealed,
    })

    setIsProofVerified(
      verifyProof({ nonce: mockNonce, messages: mockMessages, publicKey: bbsKeyPair.publicKey, proof }).verified
    )
  }

  return (
    <View style={styles.container}>
      <Button onPress={flow} title="flow" />
      <Text style={isBlsSignatureVerified ? styles.green : styles.red}>bls Signature</Text>
      <Text style={isBlsProofVerified ? styles.green : styles.red}>bls Proof</Text>
      <Text style={isSignatureVerified ? styles.green : styles.red}>Signature</Text>
      <Text style={isProofVerified ? styles.green : styles.red}>Proof</Text>
    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  green: {
    color: '#00ff00',
  },
  red: {
    color: '#ff0000',
  },
})
