file(GLOB_RECURSE sources_character
    ${CMAKE_CURRENT_SOURCE_DIR}/character/* 
    ${CMAKE_SOURCE_DIR}/include/character/*
)
file(GLOB_RECURSE sources_display
    ${CMAKE_CURRENT_SOURCE_DIR}/display/* 
    ${CMAKE_SOURCE_DIR}/include/display/*
)

file(GLOB_RECURSE sources_main
    ${CMAKE_CURRENT_SOURCE_DIR}/Main/* 
    ${CMAKE_SOURCE_DIR}/include/Main/*
)

set(core_sources
    ${sources_character}
    ${sources_display}
    ${sources_main}
)

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(
    SYSTEM ${SFML_INCLUDE_DIR}
    SYSTEM ${Boost_INCLUDE_DIRS}
)

link_directories(${CMAKE_SOURCE_DIR}/dep/bin/)

# Include dependence headers.
include_directories(${CMAKE_SOURCE_DIR}/dep/)

set(CORE_NAME miraiVN)

#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

#add_library(
add_executable(
    ${CORE_NAME}
    #SHARED
    ${core_sources}
)

target_link_libraries(
    ${CORE_NAME}
    ${SFML_LIBRARIES}
    ${Boost_LIBRARIES}
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Link Mirai Project debug.
    target_link_libraries(
        ${CORE_NAME}
        MiraiProject-d
    )
else()
    # Link Mirai Project release.
    target_link_libraries(
        ${CORE_NAME}
        MiraiProject
    )
endif()

file(COPY ${CMAKE_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/bin/resources/)