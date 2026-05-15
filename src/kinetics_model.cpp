#include "../include/kinetics_model.h"
#include <cmath>

KineticsModel::KineticsModel(const Enzyme& e)
    : enzyme(e) {}


MichaelisMenten::MichaelisMenten(const Enzyme& e)
    : KineticsModel(e) {}


double MichaelisMenten::calculateVelocity(double substrate) {

    double adjustedVmax = enzyme.adjustedVmax();

    return (adjustedVmax * substrate) /
           (enzyme.getKm() + substrate);
}


CompetitiveInhibition::CompetitiveInhibition(
    const Enzyme& e,
    double inhibitorConc
)
    : KineticsModel(e), inhibitor(inhibitorConc) {}


double CompetitiveInhibition::calculateVelocity(double substrate) {

    double effectiveKm = enzyme.getKm() * (1 + inhibitor);

    double vmax = enzyme.adjustedVmax();

    return (vmax * substrate)
           / (effectiveKm + substrate);
}


NonCompetitiveInhibition::NonCompetitiveInhibition(
    const Enzyme& e,
    double inhibitorConc
)
    : KineticsModel(e), inhibitor(inhibitorConc) {}


double NonCompetitiveInhibition::calculateVelocity(double substrate) {

    double reducedVmax = enzyme.adjustedVmax() / (1 + inhibitor);

    return (reducedVmax * substrate)
           / (enzyme.getKm() + substrate);
}