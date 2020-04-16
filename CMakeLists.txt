cmake_minimum_required(VERSION 3.10)
project(libxrouter-sampleproj-cpp)

#set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE -O3) # do not set -DNDEBUG (assert required in release)
if(UNIX AND NOT APPLE)
    set(CMAKE_C_COMPILER "/usr/bin/gcc-8")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++-8")
endif()

set(LIBS ${CMAKE_DL_LIBS})

include_directories(${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/include
        ${CMAKE_SOURCE_DIR}/blocknet/src)

set(LIBS ${LIBS}
        ${CMAKE_SOURCE_DIR}/blocknet/src/libbitcoin_server.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/xrouter/libxrouter.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/xbridge/libxbridge.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/libbitcoin_server.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/libbitcoin_common.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/univalue/.libs/libunivalue.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/libbitcoin_util.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/libbitcoin_zmq.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/libbitcoin_consensus.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/crypto/libbitcoin_crypto_base.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/crypto/libbitcoin_crypto_blocknet.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/crypto/libbitcoin_crypto_avx2.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/crypto/libbitcoin_crypto_shani.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/crypto/libbitcoin_crypto_sse41.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/leveldb/libleveldb.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/leveldb/libleveldb_sse42.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/leveldb/libmemenv.a
        ${CMAKE_SOURCE_DIR}/blocknet/src/secp256k1/.libs/libsecp256k1.a

        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libboost_system-mt.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libboost_filesystem-mt.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libboost_thread-mt.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libboost_chrono-mt.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libboost_date_time-mt.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libcrypto.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libevent.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libevent_pthreads.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libminiupnpc.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libssl.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libz.a
        ${CMAKE_SOURCE_DIR}/blocknet/depends/x86_64-pc-linux-gnu/lib/libzmq.a

        -pthread
)

set(SRC src/main.cpp)

add_executable(xrouter-dev ${SRC})
target_compile_definitions(xrouter-dev PUBLIC HAVE_CONFIG_H BOOST_SP_USE_STD_ATOMIC BOOST_AC_USE_STD_ATOMIC HAVE_BUILD_INFO __STDC_FORMAT_MACROS)
target_compile_options(xrouter-dev PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-std=c++11 -Wno-parentheses -Wno-reorder -Wno-deprecated-declarations> -fPIE)
target_include_directories(xrouter-dev PUBLIC
        ${CMAKE_SOURCE_DIR}/blocknet/src
        ${CMAKE_SOURCE_DIR}/blocknet/src/secp256k1/include
        ${CMAKE_SOURCE_DIR}/blocknet/src/univalue/include)
target_link_libraries(xrouter-dev ${LIBS})
