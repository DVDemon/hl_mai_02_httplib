cmake_minimum_required(VERSION 3.2)

project(hl_mai_02_httplib)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

if(OPENSSL_FOUND)
    set(HTTPLIB_IS_USING_OPENSSL TRUE)
endif()

set(CLIENT_NAME "client")
set(SERVER_NAME "server")

add_executable(${CLIENT_NAME} client_main.cpp)
add_executable(${SERVER_NAME} server_main.cpp)

target_link_libraries(${CLIENT_NAME} ${CMAKE_THREAD_LIBS_INIT}
                                     OpenSSL::SSL
                                     OpenSSL::Crypto)
target_link_libraries(${SERVER_NAME} ${CMAKE_THREAD_LIBS_INIT}
                                     OpenSSL::SSL
                                     OpenSSL::Crypto)