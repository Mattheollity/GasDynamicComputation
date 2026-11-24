
#pragma once

#include "IRiemannSolver.h"
#include "ExactRiemannSolution.h"
#include "IEquationOfState.h"

namespace gasdynamics::riemann {

struct ExactSolverSettings {
    double tolerance = 1e-6;
    int max_iterations = 100;
};

class ExactRiemannSolver final
    : public IRiemannSolver {

public:
    ExactRiemannSolver(
        const physics::IEquationOfState& eos,
        const ExactSolverSettings& settings
    );

    physics::Flux solve(
        const RiemannProblem& problem
    ) const override;

    ExactRiemannSolution solve_exact(
        const RiemannProblem& problem
    ) const;

private:
    const physics::IEquationOfState& eos_;
    ExactSolverSettings settings_;
};

}
