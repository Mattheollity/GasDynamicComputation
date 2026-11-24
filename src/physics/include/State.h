
#pragma once

namespace gasdynamics::physics {

class IEquationOfState;

class GasState {
public:
    static GasState from_primitive(
        double rho,
        double u,
        double p,
        const IEquationOfState& eos
    );

    static GasState from_conservative(
        double rho,
        double momentum,
        double energy
    );

    double density() const;
    double velocity() const;
    double pressure(
        const IEquationOfState& eos
    ) const;

    double momentum() const;
    double total_energy() const;

    double specific_volume() const;
    double specific_internal_energy() const noexcept;

private:
    double rho_;
    double momentum_;
    double energy_;

    GasState(
        double rho,
        double momentum,
        double energy
    );
};

struct Flux {
    double mass;
    double momentum;
    double energy;
};

}
