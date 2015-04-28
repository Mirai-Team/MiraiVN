set(CORE MiraiProject)

message(STATUS "MIRAI PROJECT SOURCES PREPARATIONS")

set(LIB_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/animations/AnimatedSprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animations/Animation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/encryption/Encryption.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inputManager/Binding.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inputManager/KeyboardManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inputManager/MouseManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/parser/Parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/resourcesManagers/AutoResManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/resourcesManagers/BaseResManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/resourcesManagers/EncryptedResManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/scene/Node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stat/BaseStat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stat/ModifiedStat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stat/VitalStat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/updateSystem/Updatable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/updateSystem/UpdateModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util/FilesUtilities.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util/LogStream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util/StringUtilities.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util/TransformableUtilities.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/util/WindowManager.cpp
)

message("   -> Prepared: Core sources")

if(OS_LINUX)
    set(LIB_SRC
        ${LIB_SRC}
    )
    message("   -> Prepared: Linux sources")
elseif(OS_WINDOWS)
    set(LIB_SRC
        ${LIB_SRC}
    )
    message("   -> Prepared: Windows sources")
endif()

# Include library headers.
include_directories(${CMAKE_SOURCE_DIR}/dep/MiraiProject/include/)

message(STATUS "MIRAI PROJECT PREPARATIONS COMPLETE")

# Add SFML and Boost.
# The parameter SYSTEM is to treat headers found there as system headers, and 
# suppress warnings originating from there by using the -isystem flag instead 
# of the -I flag while building with gcc/g++.
include_directories(
    SYSTEM ${SFML_INCLUDE_DIR}
    SYSTEM ${Boost_INCLUDE_DIRS}
)

# Set output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/dep/MiraiProject/)

# Create MiraiProject library.
add_library(
    ${CORE}
    SHARED
    ${LIB_SRC}
)


set_target_properties(${CORE} PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set_target_properties(${CORE} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

# Link SFML and Boost.
target_link_libraries(
    ${CORE}
    ${SFML_LIBRARIES}
    ${Boost_LIBRARIES}
)