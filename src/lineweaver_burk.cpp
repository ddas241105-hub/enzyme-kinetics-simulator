#include "../include/lineweaver_burk.h"
#include <cmath>

std::vector<double> LineweaverBurk::inverseSubstrate(
    const std::vector<double>& substrate) {

    std::vector<double> inverse;

    for (double s : substrate) {

        if (s != 0)
            inverse.push_back(1.0 / s);
        else
            inverse.push_back(0);
    }

    return inverse;
}

std::vector<double> LineweaverBurk::inverseVelocity(
    const std::vector<double>& velocity) {

    std::vector<double> inverse;

    for (double v : velocity) {

        if (v != 0)
            inverse.push_back(1.0 / v);
        else
            inverse.push_back(0);
    }

    return inverse;
}