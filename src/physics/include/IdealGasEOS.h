
#pragma once

#include "IEquationOfState.h"

namespace gasdynamics::physics {

class IdealGasEOS final : public IEquationOfState {
public:
    IdealGasEOS(
        double gamma,
        double gas_constant
    );

    double density(
        const GasState& state
    ) const override;

    double specific_volume(
        const GasState& state
    ) const override;

    double pressure(
        const GasState& state
    ) const override;

    double temperature(
        const GasState& state
    ) const override;

    double sound_speed(
        const GasState& state
    ) const override;

    double specific_internal_energy(
        const GasState& state
    ) const override;

    double specific_enthalpy(
        const GasState& state
    ) const override;

    double entropy_difference(
        const GasState& first,
        const GasState& second
    ) const override;

    double specific_internal_energy(
        double rho,
        double p
    ) const override;

    double gamma() const noexcept;
    double gas_constant() const noexcept;

private:
    double gamma_;
    double gas_constant_;
};

}

