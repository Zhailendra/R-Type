cmake_minimum_required(VERSION 3.5)

project(rtype_test)
set(CMAKE_CXX_STANDARD 23)

# Spécifiez le répertoire de construction (où CMake générera les fichiers générés)
set(BUILD_DIR "${CMAKE_BINARY_DIR}/build")
set(SFML_DIR "${CMAKE_SOURCE_DIR}/../libs/sfml")  # Répertoire source de SFML

add_subdirectory(${SFML_DIR} ${BUILD_DIR}/sfml)  # Utilisez le répertoire de construction

include_directories(${SFML_DIR}/include)
include_directories(../src/common)

# Définition des fichiers source de test
file(GLOB_RECURSE TEST_SOURCES
    "common/*.cpp"
    "common/*.hpp"
    "../src/common/Network/Byte.cpp"
    "../src/common/Network/Byte.hpp"
    "../src/common/ECS/Entity.cpp"
    "../src/common/ECS/System/MovableSystem/MovableSystem.cpp"
    "../src/common/ECS/System/MovableSystem/MovableSystem.hpp"
    "../src/common/ECS/System/PlayerSystem/PlayerSystem.cpp"
    "../src/common/ECS/System/PlayerSystem/PlayerSystem.hpp"
    "../src/common/ECS/System/ScaleSystem/ScaleSystem.cpp"
    "../src/common/ECS/System/ScaleSystem/ScaleSystem.hpp"
    "../src/common/ECS/System/EnemySystem/EnemySystem.cpp"
    "../src/common/ECS/System/EnemySystem/EnemySystem.hpp"
    "../src/common/ECS/System/ASystem.cpp"
    "../src/common/ECS/System/ASystem.hpp"
    "../src/common/ECS/System/ISystem.cpp"
    "../src/common/ECS/System/ISystem.hpp"
    "../src/common/ECS/Components/Enemy/EnemyComponent.cpp"
    "../src/common/ECS/Components/Enemy/EnemyComponent.hpp"
    "../src/common/ECS/Components/Button/ButtonComponent.cpp"
    "../src/common/ECS/Components/Button/ButtonComponent.hpp"
    "../src/common/ECS/Components/Scale/ScaleComponent.cpp"
    "../src/common/ECS/Components/Scale/ScaleComponent.hpp"
    "../src/common/ECS/Components/Rectable/Rectable.cpp"
    "../src/common/ECS/Components/Rectable/Rectable.hpp"
    "../src/common/ECS/Components/Position/PositionComponent.cpp"
    "../src/common/ECS/Components/Position/PositionComponent.hpp"
    "../src/common/ECS/Components/Controllable/ControllableComponent.cpp"
    "../src/common/ECS/Components/Controllable/ControllableComponent.hpp"
    "../src/common/ECS/Components/Rectable/Rectable.cpp"
    "../src/common/ECS/Components/Rectable/Rectable.hpp"
    "../src/common/ECS/Components/Renderable/Renderable.cpp"
    "../src/common/ECS/Components/Renderable/Renderable.hpp"
    "../src/common/ECS/Components/SendOverNetwork/SendOverNetworkComponent.cpp"
    "../src/common/ECS/Components/SendOverNetwork/SendOverNetworkComponent.hpp"
    "../src/common/ECS/Components/Velocity/Velocity.cpp"
    "../src/common/ECS/Components/AComponent.cpp"
    "../src/common/ECS/Components/AComponent.hpp"
    "../src/common/ECS/Components/IComponent.cpp"
    "../src/common/ECS/Components/IComponent.hpp"
    "../src/common/ECS/EntityManager.cpp"
    "../src/common/ECS/EntityManager.hpp"
    "../src/common/ECS/Entity.hpp"
    "../src/common/ECS/Components/Velocity/Velocity.hpp"
)


add_executable(rtype_test ${TEST_SOURCES})

target_link_libraries(rtype_test PRIVATE criterion sfml-system sfml-window sfml-graphics sfml-network sfml-audio)  # Remplacez CommonLib par la bibliothèque que vous utilisez pour les tests

enable_testing()
add_test(NAME rtype_test COMMAND rtype_test)
