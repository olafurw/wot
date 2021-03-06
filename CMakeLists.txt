cmake_minimum_required (VERSION 2.8)
project(sammy)

set(CMAKE_C_COMPILER	"gcc")
set(CMAKE_CXX_COMPILER	"g++")
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -O0 -coverage")

add_executable(server 
	main.cpp 
    utils/utils.cpp 
    utils/sha/sha256.cpp 
    log.cpp 
    request.cpp 
    response.cpp 
    server.cpp 
    domain_storage.cpp 
    domain.cpp 
    session_storage.cpp
    cache_storage.cpp 
    thread/worker.cpp 
    thread/pool.cpp)

target_link_libraries(server pthread)

FIND_PACKAGE(CxxTest REQUIRED)
IF(CXXTEST_FOUND)
    INCLUDE_DIRECTORIES(${CXXTEST_INCLUDE_DIR})
    ENABLE_TESTING()

    IF(NOT IS_DIRECTORY "tests")
        FILE(MAKE_DIRECTORY "tests")
    ENDIF()
    ADD_SUBDIRECTORY("tests")
ENDIF()
