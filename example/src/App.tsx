import * as React from 'react'
import { View, Text } from 'react-native'

import { turboModule } from 'react-native-bbs-signatures'

export default function App() {
  return (
    <View>
      <Text>Result: {turboModule.multiply(1, 2)}</Text>
    </View>
  )
}
