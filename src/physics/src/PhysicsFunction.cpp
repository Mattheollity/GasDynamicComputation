
#include "PhysicsFunction.h"
#include "IEquationOfState.h"

namespace gasdynamics::physics {

Flux physical_flux(
    const GasState& state,
    const IEquationOfState& eos
) {
    const double p = eos.pressure(state);
    const double u = state.velocity();

    return Flux{
        state.momentum(),
        state.momentum() * u + p,
        u * (state.total_energy() + p)
    };
}

}
