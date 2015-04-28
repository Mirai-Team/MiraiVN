project(MiraiVN)

cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

set(CMAKE_DISABLE_SOURCE_CHANGES ON)

# Disable possibility to write binary in sources directory.
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Enable debug mode by default
if( NOT CMAKE_BUILD_TYPE )
    set(CMAKE_BUILD_TYPE "Debug")
endif()

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)

# Set default build options and display them.
include(cmake/options.cmake)

# Find any version 2.X of SFML
find_package(SFML 2.0 REQUIRED system window graphics audio network)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

# Find any 1.54.X or higher version of Boost.
find_package(Boost 1.54.0 REQUIRED filesystem system thread)

if(MVN_WITH_GIT)
    find_package(Git)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    include(cmake/macros/gcc-settings.cmake)
elseif(CMAKE_CXX_COMPILER MATCHES "clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    include(cmake/macros/clang-settings.cmake)
endif()

include(cmake/genrev.cmake)

message("")

message("* MiraiVN                  : ${revHash} ${revDate} (${revBranch} branch)")
message("* MiraiVN buildtype        : ${CMAKE_BUILD_TYPE}")

if(MVN_WITH_WARNINGS)
    message("* Show all warnings        : Yes (default)")
else()
    message("* Show all warnings        : No")
endif()

if(MVN_WITH_GIT)
    message("* Use GIT revision hash    : Yes (default)")
else()
    message("* Use GIT revision hash    : No")
endif()

message("")

add_subdirectory(dep)

# Add subdirectories to the build.
add_subdirectory(src)