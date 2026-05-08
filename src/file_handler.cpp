#include "../include/file_handler.h"
#include <fstream>

std::vector<double> FileHandler::readInput(const std::string& filename) {
    std::vector<double> data;
    std::ifstream file(filename);

    double value;

    while (file >> value) {
        data.push_back(value);
    }

    return data;
}

void FileHandler::writeOutput(
    const std::string& filename,
    const std::vector<double>& data
) {
    std::ofstream file(filename);    for (double v : data) {
        file << v << std::endl;
    }
}

void FileHandler::writeCSV(
    const std::string& filename,
    const std::vector<double>& time,
    const std::vector<double>& substrate,
    const std::vector<double>& velocity,
    const std::vector<double>& conversion
) {
    std::ofstream file(filename);

    file << "Time,Substrate,Velocity,Conversion\n";

    for (size_t i = 0; i < time.size(); i++) {
        file << time[i] << ","
             << substrate[i] << ","
             << velocity[i] << ","
             << conversion[i]
             << "\n";
    }
}

