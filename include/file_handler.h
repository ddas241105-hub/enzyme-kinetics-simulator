#pragma once
#include <vector>
#include <string>

class FileHandler {
public:
    static std::vector<double> readInput(const std::string& filename);
    static void writeOutput(const std::string& filename, const std::vector<double>& data);
};