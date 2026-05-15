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

    double optimalTemp = 310.15;

    double sigma = 15.0;

    double exponent =
        -pow(temperature - optimalTemp, 2)
        / (2 * sigma * sigma);

    double activityFactor = exp(exponent);

    return Vmax * activityFactor;
}   