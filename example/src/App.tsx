import * as React from 'react'
import { StyleSheet, Text, View, Button } from 'react-native'
import { generateBls12381G2KeyPair, sign, verify } from 'react-native-bbs-signatures'

const mockMessages = [new Uint8Array([1, 2, 3, 4])]

export default function App() {
  const signFunc = () => {
    const keyPair = generateBls12381G2KeyPair()
    const signature = sign({ keyPair: { ...keyPair, messageCount: mockMessages.length }, messages: mockMessages })
    const x = verify({ publicKey: keyPair.publicKey, signature, messages: mockMessages })
    console.log('lala: ', x)
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
