#include "IdealGasEOS.h"
#include "State.h"

#include <cmath>
#include <stdexcept>

namespace gasdynamics::physics {

namespace {

void require_positive_finite(
    double value,
    const char* name
) {
    if (!std::isfinite(value) || value <= 0.0) {
        throw std::invalid_argument(name);
    }
}

}

IdealGasEOS::IdealGasEOS(
    double gamma,
    double gas_constant
)
    : gamma_(gamma),
      gas_constant_(gas_constant)
{
    if (!std::isfinite(gamma_) || gamma_ <= 1.0) {
        throw std::invalid_argument(
            "gamma must be finite and greater than 1"
        );
    }

    require_positive_finite(
        gas_constant_,
        "gas constant must be positive and finite"
    );
}

double IdealGasEOS::specific_internal_energy(
    double rho,
    double p
) const {
    require_positive_finite(
        rho, "density must be positive and finite"
    );
    require_positive_finite(
        p, "pressure must be positive and finite"
    );

    return p / ((gamma_ - 1.0) * rho);
}

double IdealGasEOS::density(
    const GasState& state
) const {
    return state.density();
}

double IdealGasEOS::specific_volume(
    const GasState& state
) const {
    return state.specific_volume();
}

double IdealGasEOS::pressure(
    const GasState& state
) const {
    const double p =
        (gamma_ - 1.0)
        * state.density()
        * state.specific_internal_energy();

    require_positive_finite(
        p, "gas pressure must be positive and finite"
    );

    return p;
}

double IdealGasEOS::temperature(
    const GasState& state
) const {
    return pressure(state)
        / (state.density() * gas_constant_);
}

double IdealGasEOS::sound_speed(
    const GasState& state
) const {
    return std::sqrt(
        gamma_ * pressure(state) / state.density()
    );
}

double IdealGasEOS::specific_internal_energy(
    const GasState& state
) const {
    (void)pressure(state);
    return state.specific_internal_energy();
}

double IdealGasEOS::specific_enthalpy(
    const GasState& state
) const {
    return specific_internal_energy(state)
        + pressure(state) / state.density();
}

double IdealGasEOS::entropy_difference(
    const GasState& first,
    const GasState& second
) const {
    const double cv =
        gas_constant_ / (gamma_ - 1.0);

    return cv * std::log(
        temperature(second) / temperature(first)
    ) + gas_constant_ * std::log(
        specific_volume(second)
        / specific_volume(first)
    );
}

double IdealGasEOS::gamma() const noexcept {
    return gamma_;
}

double IdealGasEOS::gas_constant() const noexcept {
    return gas_constant_;
}

}

