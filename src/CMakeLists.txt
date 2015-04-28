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

link_directories(${CMAKE_BINARY_DIR}/bin/)

# Include dependence headers.
include_directories(${CMAKE_SOURCE_DIR}/dep/MiraiProject/include/)

set(CORE_NAME miraiVN)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/mvn)

#add_library(
add_executable(
    ${CORE_NAME}
    ${core_sources}
)

target_link_libraries(
    ${CORE_NAME}
    ${SFML_LIBRARIES}
    ${Boost_LIBRARIES}
    MiraiProject
)

file(COPY ${CMAKE_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/bin/mvn/resources/)