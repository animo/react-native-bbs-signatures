package com.reactnativebbssignatures;

import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.module.annotations.ReactModule

@ReactModule(name = BbsSignaturesModule.NAME)
class BbsSignaturesModule(reactContext: ReactApplicationContext?) : ReactContextBaseJavaModule(reactContext) {
  companion object {
    const val NAME = "BbsSignatures"

    init {
      try {
        // Used to load the 'my_turbo_utils' library on application startup.
        System.loadLibrary("bbs_signatures")
      } catch (ignored: Exception) {
      }
    }
  }

  private val nativeProxy = NativeProxy()

  override fun getName() = NAME

  // JSI functions are installed when module is initialized
  override fun initialize() {
    super.initialize()
    nativeProxy.installJsi(this.reactApplicationContext)
  }
}
