cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0048 NEW)
project(labSort VERSION 0.0.1 LANGUAGES CXX)

include(CMakePrintHelpers)

if(CMAKE_VERSION VERSION_LESS 3.14) 
    cmake_print_variables(CMAKE_VERSION)
    # for old linux with cmake between 3.10 and 3.14
    message(FATAL_ERROR "The professor has old cmake magic for Ubuntu 18.04. If you need it, contact him" )   
else() # version 3.14 needed for new cmake magic
    # new cmake magic, from gtest docs
    # https://google.github.io/googletest/quickstart-cmake.html
    
    # GoogleTest requires at least C++11
    set(CMAKE_CXX_STANDARD 11)

    include(FetchContent)
        FetchContent_Declare(
        googletest
        # commit e2239 = release 1.11.0 210611
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
        )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

# Now simply link your own targets against gtest, gmock, etc. as appropriate

include(GoogleTest)

SET(CES12_SRC "src" CACHE FILEPATH "Directory with student sources")

include_directories( ${CES12_SRC} include lib )

FILE(GLOB libLabSortSrc lib/*.cpp)
add_library(libLabSort ${libLabSortSrc})

FILE(GLOB LabSources ${CES12_SRC}/*.cpp)
add_executable(labSorttests test/testSort.cpp ${LabSources})

target_link_libraries(labSorttests gtest gtest_main libLabSort)
 
gtest_discover_tests(labSorttests)




