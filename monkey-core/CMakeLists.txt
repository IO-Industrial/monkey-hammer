add_project(monkey-core "Core library for the Monkey Hammer project")

set(CORE_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/monkey/core)

if(VERSION_STRING)
    set(MONKEY_VERSION_STRING ${VERSION_STRING})
    message(STATUS "Updating version info to ${VERSION_STRING}")
    if(EXISTS ${SDK_CORE_INC_DIR}/VersionConfig.h})
        FILE(REMOVE ${SDK_CORE_INC_DIR/VersionConfig.h})
    endif()
    string(REPLACE "." ";" VERSION_LIST ${VERSION_STRING})
    list(GET VERSION_LIST 0 MONKEY_VERSION_MAJOR)
    list(GET VERSION_LIST 1 MONKEY_VERSION_MINOR)
    list(GET VERSION_LIST 2 MONKEY_VERSION_PATCH)

    configure_file(
        "${CORE_INC_DIR}/VersionConfig.h.in"
        "${CORE_INC_DIR}/VersionConfig.h"
        NEWLINE_STYLE LF)
else()
    message("Not able to compute versioning string, not updating.")
endif()

file(GLOB MONKEY_HEADERS "include/monkey/core/*.h")
file(GLOB MONKEY_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

file(GLOB MONKEY_COMMON_SRC
	${MONKEY_SOURCE}
    ${MONKEY_CONFIG_SRC}
    ${MONKEY_FORMATTERS_SRC}
    ${MONKEY_PARSER_SRC}
)

file(GLOB MONKEY_COMMON_HEADERS
	${MONKEY_HEADERS}
	${MONKEY_PATTERN_HEADERS}
    ${MONKEY_CONFIG_HEADERS}
    ${MONKEY_FORMATTERS_HEADERS}
    ${MONKEY_PARSER_HEADERS}
)

message("PROJECT_NAME = ${PROJECT_NAME}")

add_library(${PROJECT_NAME} ${LIBTYPE} ${MONKEY_COMMON_SRC})
add_library(MONKEY::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(Core_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_include_directories(${PROJECT_NAME} PRIVATE "${Core_INCLUDES}")

install (FILES ${MONKEY_COMMON_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/monkey/core)

