#pragma once
#include <vector>
#include <string>

class FileHandler {
public:
    static std::vector<double> readInput(const std::string& filename);

    static void writeOutput(
        const std::string& filename,
        const std::vector<double>& data
    );

    static void writeCSV(
        const std::string& filename,
        const std::vector<double>& time,
        const std::vector<double>& substrate,
        const std::vector<double>& velocity,
        const std::vector<double>& conversion
    );
};