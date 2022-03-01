import * as React from 'react'
import { StyleSheet, Text, View, Button } from 'react-native'
import {
  ProofMessageType,
  createProof,
  generateBls12381G2KeyPair,
  sign,
  verify,
  verifyProof,
} from 'react-native-bbs-signatures'

const mockMessages = [new Uint8Array([1, 2, 3, 4])]
const mockNonce = new Uint8Array([1, 2, 3])
const revealed = [ProofMessageType.Revealed]

export default function App() {
  const signFunc = () => {
    const { publicKey, secretKey } = generateBls12381G2KeyPair()
    const signature = sign({
      keyPair: { publicKey, secretKey, messageCount: mockMessages.length },
      messages: mockMessages,
    })
    const verifiedSignature = verify({ publicKey: publicKey, signature, messages: mockMessages })
    const proof = createProof({ signature, messages: mockMessages, publicKey, revealed, nonce: mockNonce })
    const verifiedProof = verifyProof({ nonce: mockNonce, proof, messages: mockMessages, publicKey })
    console.log('verified Sig: ', JSON.stringify(verifiedSignature))
    console.log('proof: ', JSON.stringify(proof))
    console.log('verified proof: ', JSON.stringify(verifiedProof))
  }

  return (
    <View style={styles.container}>
      <Button onPress={signFunc} title="sign and verify" />
    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
})
