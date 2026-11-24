
#include "State.h"
#include "IEquationOfState.h"

#include <cmath>
#include <stdexcept>

namespace gasdynamics::physics {

namespace {

void require_finite(double value, const char* name) {
    if (!std::isfinite(value)) {
        throw std::invalid_argument(name);
    }
}

}

GasState::GasState(
    double rho,
    double momentum,
    double energy
)
    : rho_(rho),
      momentum_(momentum),
      energy_(energy)
{
    require_finite(rho, "density must be finite");
    require_finite(momentum, "momentum must be finite");
    require_finite(energy, "energy must be finite");

    if (rho <= 0.0) {
        throw std::invalid_argument(
            "density must be positive"
        );
    }
}

GasState GasState::from_primitive(
    double rho,
    double u,
    double p,
    const IEquationOfState& eos
) {
    require_finite(rho, "density must be finite");
    require_finite(u, "velocity must be finite");
    require_finite(p, "pressure must be finite");

    if (rho <= 0.0 || p <= 0.0) {
        throw std::invalid_argument(
            "density and pressure must be positive"
        );
    }

    const double e =
        eos.specific_internal_energy(rho, p);

    return GasState(
        rho,
        rho * u,
        rho * e + 0.5 * rho * u * u
    );
}

GasState GasState::from_conservative(
    double rho,
    double momentum,
    double energy
) {
    return GasState(rho, momentum, energy);
}

double GasState::density() const {
    return rho_;
}

double GasState::velocity() const {
    return momentum_ / rho_;
}

double GasState::pressure(
    const IEquationOfState& eos
) const {
    return eos.pressure(*this);
}

double GasState::momentum() const {
    return momentum_;
}

double GasState::total_energy() const {
    return energy_;
}

double GasState::specific_volume() const {
    return 1.0 / rho_;
}

double GasState::specific_internal_energy()
    const noexcept
{
    return energy_ / rho_
        - 0.5 * velocity() * velocity();
}

}
