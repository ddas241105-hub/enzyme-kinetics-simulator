#pragma once
#include "enzyme.h"

class Reaction {
private:
    Enzyme enzyme;

public:
    Reaction(Enzyme e);
    double calculateVelocity(double substrate);
};