
#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "IRiemannSolver.h"
#include "IEquationOfState.h"

namespace gasdynamics::riemann {

class RiemannSolverFactory {
public:
    using RSCreator = std::function<
        std::unique_ptr<IRiemannSolver>(
            const physics::IEquationOfState& eos
        )
    >;

    void register_solver(
        const std::string& name,
        RSCreator creator
    );

    std::unique_ptr<IRiemannSolver> create(
        const std::string& name,
        const physics::IEquationOfState& eos
    ) const;

private:
    std::unordered_map<std::string, RSCreator> creators_;
};

}

