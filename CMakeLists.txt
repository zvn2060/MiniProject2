CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Mini2)

SET(CMAKE_BUILD_TYPE DEBUG)
SET(CMAKE_C_STANDARD C++14)
SET(CMAKE_CXX_FLAGS "-g -Wall")
set(EXECUTABLE_OUTPUT_PATH ../game/)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/ SOURCE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Scenes/ SOURCE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Bullet/ SOURCE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Turret/ SOURCE_FILES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Enemy/ SOURCE_FILES)

INCLUDE_DIRECTORIES(
        ${CMAKE_SOURCE_DIR}/allegro5/include/
        ${CMAKE_SOURCE_DIR}/include/
        ${CMAKE_SOURCE_DIR}/include/Scenes/
        ${CMAKE_SOURCE_DIR}/include/Bullet/
        ${CMAKE_SOURCE_DIR}/include/Turret/
        ${CMAKE_SOURCE_DIR}/include/Enemy/
        )
LINK_DIRECTORIES(
        ${CMAKE_SOURCE_DIR}/allegro5/lib/
)

add_executable(Mini2 ${SOURCE_FILES} include/Scenes/MainScene.hpp)

TARGET_LINK_LIBRARIES(Mini2 ${CMAKE_SOURCE_DIR}/liballegro_monolith-debug.dll.a)