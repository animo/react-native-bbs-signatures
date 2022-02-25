import * as React from 'react'
import { StyleSheet, Text, View, Button } from 'react-native'
import { generateBls12381G1KeyPair, sign } from 'react-native-bbs-signatures'

const mockMessages = [new Uint8Array([1, 2, 3, 4])]

export default function App() {
  const signFunc = () => {
    const keyPair = generateBls12381G1KeyPair()
    sign({ keyPair: { ...keyPair, messageCount: mockMessages.length }, messages: mockMessages })
  }

  return (
    <View style={styles.container}>
      <Button onPress={signFunc} title="sign">
        sign()
      </Button>
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
