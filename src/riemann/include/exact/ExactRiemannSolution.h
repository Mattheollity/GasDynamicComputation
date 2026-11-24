
#pragma once

#include <array>
#include "RiemannProblem.h"

namespace gasdynamics::riemann {

enum class WaveType {
    Shock,
    Rarefaction
};

struct Wave {
    WaveType type;

    double head_speed;
    double tail_speed;
};

struct ExactRiemannSolution {
    std::array<physics::GasState, 2> initial_states;
    std::array<physics::GasState, 2> star_states;
    std::array<Wave, 2> waves;

    double pressure_star;
    double velocity_star;
    double contact_speed;

    double gamma;

    double initial_pressure_guess;
    int iterations;

    physics::GasState sample(double S) const;
};

}
