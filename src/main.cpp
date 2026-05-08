#include <iostream>
#include <vector>
#include <iomanip>

#include "../include/enzyme.h"
#include "../include/kinetics_model.h"
#include "../include/file_handler.h"

int main() {
    Enzyme enzyme(0.5, 10);

    MichaelisMenten normalModel(enzyme);
    CompetitiveInhibition competitiveModel(enzyme, 2.0, 1.0);
    NonCompetitiveInhibition nonCompetitiveModel(enzyme, 2.0, 1.0);

    double dt = 0.01;
    int steps = 1000;

    double initialSubstrate = 5.0;

    double S_normal = initialSubstrate;
    double S_comp = initialSubstrate;
    double S_noncomp = initialSubstrate;

    std::vector<double> time_history;

    std::vector<double> substrate_normal;
    std::vector<double> substrate_comp;
    std::vector<double> substrate_noncomp;

    std::cout << std::setw(10) << "Time"
              << std::setw(15) << "Normal"
              << std::setw(15) << "Competitive"
              << std::setw(20) << "NonCompetitive"
              << std::endl;

    for (int i = 0; i < steps; i++) {
        double time = i * dt;

        double v_normal = normalModel.calculateVelocity(S_normal);
        double v_comp = competitiveModel.calculateVelocity(S_comp);
        double v_noncomp = nonCompetitiveModel.calculateVelocity(S_noncomp);

        S_normal -= v_normal * dt;
        S_comp -= v_comp * dt;
        S_noncomp -= v_noncomp * dt;

        if (S_normal < 0) S_normal = 0;
        if (S_comp < 0) S_comp = 0;
        if (S_noncomp < 0) S_noncomp=0;
    
        time_history.push_back(time);

        substrate_normal.push_back(S_normal);
        substrate_comp.push_back(S_comp);
        substrate_noncomp.push_back(S_noncomp);

        std::cout << std::fixed << std::setprecision(4)
                  << std::setw(10) << time
                  << std::setw(15) << S_normal
                  << std::setw(15) << S_comp
                  << std::setw(20) << S_noncomp
                  << std::endl;

        if (S_normal <= 0.001
            && S_comp <= 0.001
            && S_noncomp <= 0.001)
            break;
    }

    std::vector<double> dummy;

    FileHandler::writeCSV(
        "results/normal.csv",   
        time_history,
        substrate_normal,
        dummy,
        dummy
    );

    FileHandler::writeCSV(
        "results/competitive.csv",
        time_history,
        substrate_comp,
        dummy,
        dummy
    );

    FileHandler::writeCSV(
        "results/noncompetitive.csv",
        time_history,
        substrate_noncomp,
        dummy,
        dummy
    );

    std::cout << "\nSimulation completed successfully.\n";

    return 0;
}