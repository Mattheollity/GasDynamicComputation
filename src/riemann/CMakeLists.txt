cmake_minimum_required(VERSION 3.20)

add_library(riemann STATIC
    src/ExactRiemannSolver.cpp
    src/ExactRiemannSolution.cpp
    src/RiemannSolverFactory.cpp
)

add_library(gasdynamics::riemann ALIAS riemann)

target_include_directories(riemann
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/exact
)

target_compile_features(riemann PUBLIC cxx_std_17)
target_link_libraries(riemann PUBLIC gasdynamics::physics)
