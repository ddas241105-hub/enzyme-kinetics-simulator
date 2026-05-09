#include "../include/enzyme.h"
#include <cmath>

Enzyme::Enzyme(double km, double vmax, double temp)
    : Km(km), Vmax(vmax), temperature(temp) {}


double Enzyme::getKm() const {
    return Km;
}


double Enzyme::getVmax() const {
    return Vmax;
}


double Enzyme::getTemperature() const {
    return temperature;
}


double Enzyme::adjustedVmax() const {

    double optimum = 37.0;

    double factor = exp(-0.01 * pow(temperature - optimum, 2));

    return Vmax * factor;
}    