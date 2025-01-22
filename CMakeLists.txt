cmake_minimum_required(VERSION 3.5)

project(rtype)
set(CMAKE_CXX_STANDARD 23)

set(SFML_STATIC TRUE)
set(BUILD_SHARED_LIBS FALSE)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/sfml")
add_subdirectory(libs/sfml)
include_directories(libs/sfml/include)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
# Libs Setups
file(GLOB_RECURSE SOURCES_CLIENT
        "src/client/*.cpp"
        "src/client/*.hpp"
)

file(GLOB_RECURSE SOURCES_SERVER
        "src/server/*.cpp"
        "src/server/*.hpp"
)

file(GLOB_RECURSE SOURCES_COMMON
        "src/common/*.cpp"
        "src/common/*.hpp"
)

include_directories(src/common)
add_library(CommonLib STATIC ${SOURCES_COMMON})

add_executable(r-type_client ${SOURCES_CLIENT})

target_link_libraries(r-type_client PRIVATE CommonLib)
target_link_libraries(r-type_client PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


add_executable(r-type_server ${SOURCES_SERVER})

target_link_libraries(r-type_server PRIVATE CommonLib)
target_link_libraries(r-type_server PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

