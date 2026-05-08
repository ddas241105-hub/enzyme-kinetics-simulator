#include <iostream>
#include <vector>
#include <iomanip>
#include "../include/enzyme.h"
#include "../include/kinetics_model.h"
#include "../include/file_handler.h"

int main() {
    Enzyme enzyme(0.5, 10);

    MichaelisMenten model(enzyme);

    double S = 5.0;     // initial substrate concentration
    double dt = 0.01;     // time step
    int steps = 1000;     // simulation length

    std::vector<double> substrate_history;
    std::vector<double> velocity_history;

    std::cout << std::setw(10) << "Time"
              << std::setw(15) << "Substrate"
              << std::setw(15) << "Velocity"
              << std::setw(15) << "Conversion"
              << std::endl;

    double initialSubstrate = S;
    for (int i = 0; i < steps; i++) {
        double time = i * dt;
        double velocity = model.calculateVelocity(S);
        double conversion = ((initialSubstrate - S) / initialSubstrate) * 100;

        // simulate substrate being consumed
        S = S - velocity * dt;

        if (S < 0) S = 0;
        
        if (S <= 0.001) {
            std::cout << "\nSubstrate depleted. Simulation stopped.\n";
            break;
        }

        substrate_history.push_back(S);
        velocity_history.push_back(velocity);

        std::cout << std::fixed << std::setprecision(4)
                  << std::setw(10) << time
                  << std::setw(15) << S
                  << std::setw(15) << velocity
                  << std::setw(15) << conversion << "%"
                  << std::endl;
    }   

    FileHandler::writeOutput("results/substrate.txt", substrate_history);
    FileHandler::writeOutput("results/velocity.txt", velocity_history);

    std::cout << "\nSimulation complete.\n";

    return 0;
}