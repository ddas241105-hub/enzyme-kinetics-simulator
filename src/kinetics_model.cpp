#include "../include/kinetics_model.h"

// Michaelis-Menten
MichaelisMenten::MichaelisMenten(Enzyme e) : enzyme(e) {}

double MichaelisMenten::calculateVelocity(double S) {
    return (enzyme.getVmax() * S) / (enzyme.getKm() + S);
}

// Competitive Inhibition
CompetitiveInhibition::CompetitiveInhibition(Enzyme e, double inhibitor, double ki)
    : enzyme(e), inhibitor(inhibitor), Ki(ki) {}

double CompetitiveInhibition::calculateVelocity(double S) {
    double Km_eff = enzyme.getKm() * (1 + inhibitor / Ki);
    return (enzyme.getVmax() * S) / (Km_eff + S);
}