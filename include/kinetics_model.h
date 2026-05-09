#ifndef KINETICS_MODEL_H
#define KINETICS_MODEL_H

#include "enzyme.h"

class KineticsModel {
protected:
    Enzyme enzyme;

public:
    KineticsModel(const Enzyme& e);

    virtual double calculateVelocity(double substrate) = 0;

    virtual ~KineticsModel() {}
};


class MichaelisMenten : public KineticsModel {
public:
    MichaelisMenten(const Enzyme& e);

    double calculateVelocity(double substrate) override;
};


class CompetitiveInhibition : public KineticsModel {
private:
    double inhibitor;

public:
    CompetitiveInhibition(const Enzyme& e, double inhibitorConc);

    double calculateVelocity(double substrate) override;
};


class NonCompetitiveInhibition : public KineticsModel {
private:
    double inhibitor;

public:
    NonCompetitiveInhibition(const Enzyme& e, double inhibitorConc);

    double calculateVelocity(double substrate) override;
};

#endif