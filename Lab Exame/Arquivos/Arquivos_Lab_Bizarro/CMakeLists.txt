cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0048 NEW)
project(labTsp VERSION 0.0.1 LANGUAGES CXX)

include(CMakePrintHelpers)

if(CMAKE_VERSION VERSION_LESS 3.14) 
    cmake_print_variables(CMAKE_VERSION)
    # for old linux with cmake between 3.10 and 3.14
    message(FATAL_ERROR "The professor has old cmake magic for Ubuntu 18.04. If you need it, contact him" )
else() # version 3.14 needed for new cmake magic
    # new cmake magic, from gtest docs
    # https://google.github.io/googletest/quickstart-cmake.html
    
    # GoogleTest requires at least C++11
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    include(FetchContent)
        FetchContent_Declare(
        googletest
        # release 1.14.9 230802
        URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip

        )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

include(GoogleTest)

SET(CES12_SRC "src" CACHE FILEPATH "Directory with student sources")

include_directories( ${CES12_SRC} include lib )

FILE(GLOB libLabTspSrc lib/*.cpp)
add_library(libLabTsp ${libLabTspSrc})

FILE(GLOB LabSources ${CES12_SRC}/*.cpp)
add_executable(labTsptests test/testTsp.cpp ${LabSources})

target_link_libraries(labTsptests gtest gtest_main libLabTsp)
 
gtest_discover_tests(labTsptests)




