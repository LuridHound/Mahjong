cmake_minimum_required(VERSION 3.10)
project(Mahjong LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


# If the build type not indicated explicity, set it to the Release build.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()


# BUILD EXTERNAL LIBRARIES
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(SFML
        #GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1
        SOURCE_DIR  ${CMAKE_SOURCE_DIR}/external/SFML
        CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE})
ExternalProject_Get_Property(SFML INSTALL_DIR)
set(SFML_LIB ${INSTALL_DIR})


# ADD SOURCE FILES AND HEADERS OF EXECUTABLE
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include ${SFML_LIB}/include)

set(SOURCE
        ${CMAKE_SOURCE_DIR}/main.cpp
        )

# LINK EXTERNAL LIBRARIES TO EXECUTABLE
LINK_DIRECTORIES(${SFML_LIB}/lib)

# ADD EXECUTABLE
add_executable(Mahjong ${SOURCE})

# ADD DEPENDISIES FOR EXECUTABLE
add_dependencies(Mahjong SFML)

TARGET_LINK_LIBRARIES(Mahjong
        optimized sfml-system		debug sfml-system-d sfml-system
        optimized sfml-window		debug sfml-window-d sfml-window
        optimized sfml-graphics		debug sfml-graphics-d sfml-graphics
        optimized sfml-audio		debug sfml-audio-d sfml-audio
        optimized sfml-network		debug sfml-network-d sfml-network)

# POST BUILD SCRIPTS
set(POST_LIB_DIR "lib")
if (WIN32)
    set(POST_LIB_DIR "bin")
endif()

ADD_CUSTOM_COMMAND(TARGET Mahjong POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${SFML_LIB}/${POST_LIB_DIR}" "${CMAKE_CURRENT_BINARY_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/resources" "${CMAKE_CURRENT_BINARY_DIR}/resources")