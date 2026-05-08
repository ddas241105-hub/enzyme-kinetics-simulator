#include "../include/enzyme.h"

Enzyme::Enzyme(double km, double vmax) : Km(km), Vmax(vmax) {}

double Enzyme::getKm() const {
    return Km;
}

double Enzyme::getVmax() const {
    return Vmax;
}
