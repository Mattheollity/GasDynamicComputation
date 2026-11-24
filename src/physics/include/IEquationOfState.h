
#pragma once

namespace gasdynamics::physics {

class GasState;

class IEquationOfState {
public:
    virtual ~IEquationOfState() = default;

    virtual double density(
        const GasState& state
    ) const = 0;

    virtual double specific_volume(
        const GasState& state
    ) const = 0;

    virtual double pressure(
        const GasState& state
    ) const = 0;

    virtual double temperature(
        const GasState& state
    ) const = 0;

    virtual double sound_speed(
        const GasState& state
    ) const = 0;

    virtual double specific_internal_energy(
        const GasState& state
    ) const = 0;

    virtual double specific_internal_energy(
        double rho,
        double p
    ) const = 0;

    virtual double specific_enthalpy(
        const GasState& state
    ) const = 0;

    virtual double entropy_difference(
        const GasState& first,
        const GasState& second
    ) const = 0;
};

}
