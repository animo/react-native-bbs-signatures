cmake_minimum_required(VERSION 3.9.0)

set (PACKAGE_NAME "react-native-bbs-signatures")
set (BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

include_directories(
  ../cpp
  ../cpp/keys
  ../cpp/include
  "${NODE_MODULES_DIR}/react-native/React"
  "${NODE_MODULES_DIR}/react-native/React/Base"
  "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi"
)

add_library(reactnativebbssignatures
  SHARED
  cpp-adapter.cpp
  ../cpp/keys/util.cpp
  ../cpp/HostObject.cpp
  ../cpp/bbsSignatures.cpp
  ../cpp/keys/blsKeyPair.cpp
  ../cpp/turboModuleUtility.cpp
  ../cpp/nativeBbsSignatures.cpp
  ../cpp/keys/blindedBlsKeyPair.cpp
)


set_target_properties(
  reactnativebbssignatures PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSION OFF
  POSITION_INDEPENDENT_CODE ON
)

file (GLOB LIBRN_DIR "${PREBUILT_DIR}/${ANDROID_ABI}")

find_library(
  log-lib
  log
)

find_library(
  REACT_NATIVE_JNI_LIB
  reactnativejni
  PATHS ${LIBRN_DIR}
  NO_CMAKE_FIND_ROOT_PATH
)

find_library(
  JSI_LIB
  jsi
  PATHS ${LIBRN_DIR}
  NO_CMAKE_FIND_ROOT_PATH
)

add_library( libbbs STATIC IMPORTED )
set_target_properties(libbbs
  PROPERTIES
  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libbbs.a )

target_link_libraries(
  reactnativebbssignatures
  ${log-lib}
  ${JSI_LIB}
  ${REACT_NATIVE_JNI_LIB}
  android
  libbbs
)
