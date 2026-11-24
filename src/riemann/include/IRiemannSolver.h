
#pragma once

#include "RiemannProblem.h"

namespace gasdynamics::riemann {

class IRiemannSolver {
public:
    virtual ~IRiemannSolver() = default;

    virtual physics::Flux solve(
        const RiemannProblem& problem
    ) const = 0;
};

}
