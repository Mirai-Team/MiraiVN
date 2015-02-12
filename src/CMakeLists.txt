set(core_sources
    ${sources_display}
)

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(
    SYSTEM ${SFML_INCLUDE_DIR}
    SYSTEM ${Boost_INCLUDE_DIRS}
)

link_directories(${CMAKE_SOURCE_DIR}/dep/bin/)

# Include dependence headers.
include_directories(${CMAKE_SOURCE_DIR}/dep/)

set(CORE_NAME VNE)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_library(
    ${CORE_NAME}
    SHARED
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