#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>
#include <map>

class FileHandler {
public:
    static std::map<std::string, double>
    readConfig(const std::string& filename);


    static void writeCSV(
        const std::string& filename,
        const std::vector<double>& time,
        const std::vector<double>& substrate
    );
};

#endif