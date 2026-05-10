#ifndef LINEWEAVER_BURK_H
#define LINEWEAVER_BURK_H

#include <vector>

class LineweaverBurk {
public:

    static std::vector<double> inverseSubstrate(
        const std::vector<double>& substrate);

    static std::vector<double> inverseVelocity(
        const std::vector<double>& velocity);
};

#endif