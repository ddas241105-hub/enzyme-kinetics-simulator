#include "../include/file_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, double>
FileHandler::readConfig(const std::string& filename) {

    std::map<std::string, double> config;

    std::ifstream file(filename);

    std::string line;

    while (getline(file, line)) {

        std::stringstream ss(line);

        std::string key;
        std::string value;

        getline(ss, key, '=');
        getline(ss, value);

        config[key] = stod(value);
    }

    return config;
}


void FileHandler::writeCSV(
    const std::string& filename,
    const std::vector<double>& time,
    const std::vector<double>& substrate
) {

    std::ofstream file(filename);

    file << "Time,Substrate\n";

    for (size_t i = 0; i < time.size(); i++) {

        file << time[i]
             << ","
             << substrate[i]
             << "\n";
    }

    file.close();

    std::cout << "Saved: "
              << filename
              << std::endl;
}