#ifndef ENZYME_H
#define ENZYME_H

class Enzyme {
private:
    double Km;
    double Vmax;
    double temperature;

public:
    Enzyme(double km, double vmax, double temp);

    double getKm() const;
    double getVmax() const;
    double getTemperature() const;

    double adjustedVmax() const;
};

#endif