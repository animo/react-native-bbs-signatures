import * as React from 'react'
import { StyleSheet, Text, View, Button } from 'react-native'
import { createProof, generateBls12381G2KeyPair, sign, verify } from 'react-native-bbs-signatures'

const mockMessages = [new Uint8Array([1, 2, 3, 4])]
const mockNonce = new Uint8Array([1, 2, 3])
const revealed = [0]

export default function App() {
  const signFunc = () => {
    const { publicKey, secretKey } = generateBls12381G2KeyPair()
    const signature = sign({
      keyPair: { publicKey, secretKey, messageCount: mockMessages.length },
      messages: mockMessages,
    })
    const { verified } = verify({ publicKey: publicKey, signature, messages: mockMessages })
    const proof = createProof({ signature, messages: mockMessages, publicKey, revealed, nonce: mockNonce })
    console.log('verified: ', JSON.stringify(verified))
    console.log('proof: ', JSON.stringify(proof))
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
