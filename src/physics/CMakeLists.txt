cmake_minimum_required(VERSION 3.20)

add_library(
    physics
    STATIC
    src/IdealGasEOS.cpp
    src/State.cpp
    src/PhysicsFunction.cpp
)
add_library(gasdynamics::physics ALIAS physics)

target_include_directories(physics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(physics PUBLIC cxx_std_17)