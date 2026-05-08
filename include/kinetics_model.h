#pragma once
#include "enzyme.h"

class KineticsModel {
public:
    virtual double calculateVelocity(double S) = 0;
    virtual ~KineticsModel() {}
};

// Michaelis-Menten
class MichaelisMenten : public KineticsModel {
private:
    Enzyme enzyme;

public:
    MichaelisMenten(Enzyme e);
    double calculateVelocity(double S) override;
};

// Competitive Inhibition
class CompetitiveInhibition : public KineticsModel {
private:
    Enzyme enzyme;
    double inhibitor;
    double Ki;

public:
    CompetitiveInhibition(Enzyme e, double inhibitor, double ki);
    double calculateVelocity(double S) override;
};

// Non-Competitive Inhibition
class NonCompetitiveInhibition : public KineticsModel {
private:
    Enzyme enzyme;
    double inhibitor;
    double Ki;

public:
    NonCompetitiveInhibition(Enzyme e, double inhibitor, double ki);
    double calculateVelocity(double S) override;
};