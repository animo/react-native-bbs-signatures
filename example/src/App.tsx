import * as React from 'react'
import { StyleSheet, Text, View, Button } from 'react-native'
import {
  ProofMessageType,
  createProof,
  generateBls12381G2KeyPair,
  sign,
  verify,
  verifyProof,
  commitmentForBlindSignRequest,
  verifyBlindSignContext,
  generateBls12381G1KeyPair,
  generateBlindedBls12381G1KeyPair,
  generateBlindedBls12381G2KeyPair,
  bls12381toBbs,
} from 'react-native-bbs-signatures'

const mockMessages = [new Uint8Array([1, 2, 3, 4])]
const mockNonce = new Uint8Array([1, 2, 3])
const revealed = [ProofMessageType.Revealed]
const hidden = [0]

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
    commitmentForBlindSignRequest({ nonce: mockNonce, hidden, messages: mockMessages, publicKey })
    console.log('verified Sig: ', JSON.stringify(verifiedSignature))
    console.log('proof: ', JSON.stringify(proof))
    console.log('verified proof: ', JSON.stringify(verifiedProof))
  }

  const createKeys = () => {
    const g1KeyPair = generateBls12381G1KeyPair()
    const g2KeyPair = generateBls12381G2KeyPair()
    const blindedG1KeyPair = generateBlindedBls12381G1KeyPair()
    const blindedG2KeyPair = generateBlindedBls12381G2KeyPair()
    console.log(`        g1: pk: ${g1KeyPair.publicKey.length} sk: ${g1KeyPair.secretKey.length}`)
    console.log(`        g2: pk: ${g2KeyPair.publicKey.length} sk: ${g2KeyPair.secretKey.length}`)
    console.log(
      `blinded g1: pk ${blindedG1KeyPair.publicKey.length} sk: ${blindedG1KeyPair.secretKey.length} bf: ${blindedG1KeyPair.blindingFactor.length}`
    )
    console.log(
      `blinded g2: pk ${blindedG2KeyPair.publicKey.length} sk: ${blindedG2KeyPair.secretKey.length} bf: ${blindedG2KeyPair.blindingFactor.length}`
    )
    const blsKeyPair = bls12381toBbs({
      keyPair: { publicKey: g2KeyPair.publicKey, secretKey: g2KeyPair.secretKey },
      messageCount: 1,
    })
    console.log(
      `        bls: pk: ${blsKeyPair.publicKey.length} sk: ${blsKeyPair.secretKey?.length} mc: ${blsKeyPair.messageCount}`
    )
  }

  return (
    <View style={styles.container}>
      <Button onPress={signFunc} title="sign and verify" />
      <Button onPress={createKeys} title="create keys" />
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
