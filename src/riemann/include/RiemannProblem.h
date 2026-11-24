
#pragma once

#include <array>
#include "State.h"

namespace gasdynamics::riemann {

struct RiemannProblem {
    std::array<physics::GasState, 2> states;
    int normal_direction;
};

}
