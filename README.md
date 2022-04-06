# React Native BBS Signatures

Wrapper for React Native around [ffi-bbs-signatures](https://github.com/mattrglobal/ffi-bbs-signatures). It matches the interface from the [BBS Signatures](https://github.com/mattrglobal/bbs-signatures) library so it can be used with the [JSON-LD Signatures BBS](https://github.com/mattrglobal/jsonld-signatures-bbs) library.
This library uses the new TurboModule for increased performance, however this may causes issues when something other than `React Native 0.66.4` is used.
Most versions above `0.64.x` should work, however the library has been tested extensively with `0.66.4` and it is garanteed to work.

## Functionality

- Create key pair (bls12381g1, bls12381g2)
- Convert bls to bbs key (bls12381g1, bls12381g2)
- Sign with keypair (bls12381g2)
- Derive zero knowledge proofs with selective disclosure of attributes
- Verify signature

This library matches the public API of [bbs-signatures](https://github.com/mattrglobal/bbs-signatures) but still misses some minor functionality.

## Installation

To use this library in your React Native project run the following command:

```sh
yarn add @animo-id/react-native-bbs-signatures
```

Since autolinking is disabled for both iOS and Android the following steps also have to be done:

### iOS

We need to install the pod manually so apply the following diff:

`<PROJECT>/ios/Podfile`

```diff
require_relative '../node_modules/react-native/scripts/react_native_pods'
require_relative '../node_modules/@react-native-community/cli-platform-ios/native_modules'

platform :ios, '12.0'

target 'PROJECT' do
  config = use_native_modules!

  use_react_native!(
    :path => config[:reactNativePath],
    :hermes_enabled => true
  )

+ pod 'react-native-bbs-signatures', :path => "../node_modules/@animo-id/react-native-bbs-signatures"

  post_install do |installer|
    react_native_post_install(installer)
    __apply_Xcode_12_5_M1_post_install_workaround(installer)
  end
end
```

After this run `pod install --project-directory=ios` from the root of your project and the installation
is complete.

### Android

For Android we have to edit some more files in order for everything to work.

`<PROJECT>/android/settings.gradle`

```diff
+ include ':reactnativebbssignatures'
+ project(':reactnativebbssignatures').projectDir = new File(rootProject.projectDir, '../node_modules/@animo-id/react-native-bbs-signatures/android')
```

`<PROJECT>/android/app/build.gradle`

```diff
android {
  ...

+  packagingOptions {
+    pickFirst '**/*.so'
+  }
}

dependencies {
  ...


+  implementation (project(':reactnativebbssignatures')) {
+     exclude group:'com.facebook.fbjni'
+  }

}

```

`<PROJECT>/android/src/main/java/.../MainApplication.java`

```diff
+ import com.reactnativebbssignatures.BbsSignaturesPackage;

@Override
protected List<ReactPackage> getPackages() {
   @SuppressWarnings("UnnecessaryLocalVariable")
   List<ReactPackage> packages = new PackageList(this).getPackages();
+  packages.add(new BbsSignaturesPackage());
   return packages;
}

```

After these changes to your application everything is ready for usage.

## Credits

- [MATTR](https://github.com/mattrglobal) for providing [ffi-bbs-signatures](https://github.com/mattrglobal/ffi-bbs-signatures) and [bbs-signatures](https://github.com/mattrglobal/bbs-signatures)
  - For providing [ffi-bbs-signatures](https://github.com/mattrglobal/ffi-bbs-signatures)
  - And [bbs-signatures](https://github.com/mattrglobal/bbs-signatures)
