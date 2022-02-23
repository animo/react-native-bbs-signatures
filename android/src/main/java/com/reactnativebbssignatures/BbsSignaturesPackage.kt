package com.reactnativebbssignatures

import com.facebook.react.ReactPackage
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.uimanager.ViewManager

class BbsSignaturesPackage: ReactPackage {
  override fun createNativeModules(reactContext: ReactApplicationContext)
    = listOf(BbsSignaturesModule(reactContext))

  override fun createViewManagers(reactContext: ReactApplicationContext): List<ViewManager<*, *>>
    = emptyList()
}
