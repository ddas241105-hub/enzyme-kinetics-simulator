#ifndef SIMULATION_DATA_H
#define SIMULATION_DATA_H

#include <vector>

struct SimulationData {
    std::vector<double> time;
    std::vector<double> substrate;
    std::vector<double> velocity;
};

#endif