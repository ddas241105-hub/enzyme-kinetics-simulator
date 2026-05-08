#pragma once

class Enzyme {
private:
    double Km;
    double Vmax;

public:
    Enzyme(double km, double vmax);

    double getKm() const;
    double getVmax() const;
};