# Testing

## Prerequisites

1. cmake
2. make
3. clang

4. build the ffi-bbs-signature [library](https://github.com/mattrglobal/ffi-bbs-signatures) with `cargo build --release`

5. move the file in `target/release/*.dylib` to `cpp/tests/libs/*.dylib`

6. run `./test`
