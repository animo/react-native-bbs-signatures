# react-native-bbs-signatures

## Installation

To use this library in your React Native project run the following command:

```sh
yarn add @animo-id/react-native-bbs-signatures
```

Since autolinking is disabled for both iOS and Android the following steps also have to be done:

## iOS

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

## Android

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
