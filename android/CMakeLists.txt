cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

set(build_DIR ${CMAKE_SOURCE_DIR}/build)

# the name for our library
set(PACKAGE_NAME "bbs_signatures")

include_directories(
        ../cpp
        ../cpp/keys
        ../cpp/include
        ../cpp/generated
        "${NODE_MODULES_DIR}/react-native/React"
        "${NODE_MODULES_DIR}/react-native/React/Base"
        "${NODE_MODULES_DIR}/react-native/ReactCommon"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/callinvoker"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/jsiexecutor/jsireact"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/react/nativemodule"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/react/nativemodule/core"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/react/nativemodule/core/ReactCommon"
        "${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon"
)

# Add the correct multiply static library
add_library( libbbs STATIC IMPORTED )
set_target_properties( libbbs
  PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libbbs.a )

# find fbjni package
find_package(fbjni REQUIRED CONFIG)

# create library "bbs_signatures"
add_library(
        ${PACKAGE_NAME}
        SHARED
        "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi/jsi/jsi.cpp"
        "${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni/ReactCommon/CallInvokerHolder.cpp"
        "${NODE_MODULES_DIR}/react-native/ReactCommon/react/nativemodule/core/ReactCommon/TurboModule.cpp"
        ../cpp/TurboModuleUtils.cpp
        ../cpp/react-native-bbs-signatures.cpp
        ../cpp/bbs-signatures.cpp
        ../cpp/keys/util.cpp
        ../cpp/keys/bls-key-pair.cpp
        ../cpp/keys/blinded-bls-key-pair.cpp
        ../cpp/generated/NativeModules.cpp
        cpp-adapter.cpp
)

# link fbjni and logger to bbs_signatures
target_link_libraries(
        ${PACKAGE_NAME}
        fbjni::fbjni
        android
        log
        libbbs
)

# A workaround to avoid runtime error:
# E/SoLoader: couldn't find DSO to load: libturbomodulejsijni.so
add_library(
        turbomodulejsijni
        # Sets the library as a shared library.
        SHARED
        # an empty cpp file
        ../cpp/empty.cpp
)

