# React Native BBS Signatures

Wrapper for React Native around [ffi-bbs-signatures](https://github.com/mattrglobal/ffi-bbs-signatures). It matches the interface from the [BBS Signatures](https://github.com/mattrglobal/bbs-signatures) library so it can be used with the [JSON-LD Signatures BBS](https://github.com/mattrglobal/jsonld-signatures-bbs) library.
This library uses the new TurboModule for increased performance. `React Native >=66` is required for this library to work.

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

### iOS

On iOS you still need to run `pod install --project-directory=ios` in the root of your project to setup the native dependencies.


### Android

Since autolinking can handle everything on the Android side, no additional steps are required.

## Contributing

If you want to add functionality to this library please make sure to run the tests in the `cpp/tests` folder with your added functionality add run the React Native tests inside the `example/` app.

## Credits

- [MATTR](https://github.com/mattrglobal) for providing [ffi-bbs-signatures](https://github.com/mattrglobal/ffi-bbs-signatures) and [bbs-signatures](https://github.com/mattrglobal/bbs-signatures)
  - For providing [ffi-bbs-signatures](https://github.com/mattrglobal/ffi-bbs-signatures)
  - And [bbs-signatures](https://github.com/mattrglobal/bbs-signatures)

<hr>

This work was created as a joint effort between [Northern Block](https://northernblock.io/), [Animo Solutions](https://animo.id/) and the Ontario government, on behalf of the Ontario government.
