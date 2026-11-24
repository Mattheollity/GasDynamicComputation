
#pragma once

#include "State.h"
#include "IEquationOfState.h"

namespace gasdynamics::physics {

Flux physical_flux(
    const GasState& state,
    const IEquationOfState& eos
);

}
