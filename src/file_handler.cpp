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

void FileHandler::writeOutput(const std::string& filename, const std::vector<double>& data) {
    std::ofstream file(filename);

    for (double v : data) {
        file << v << std::endl;
    }
}