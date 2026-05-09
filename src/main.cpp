#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/enzyme.h"
#include "../include/kinetics_model.h"
#include "../include/file_handler.h"


void singleSimulation(
    KineticsModel& model,
    double initialSubstrate,
    double dt,
    double totalTime,
    const std::string& outputFile,
    const std::string& label
) {

    std::vector<double> timeData;
    std::vector<double> substrateData;

    double S = initialSubstrate;

    std::cout << "\n=== "
              << label
              << " ===\n";

    std::cout
        << std::setw(12) << "Time"
        << std::setw(18) << "Substrate"
        << std::endl;

    int steps = totalTime / dt;

    for (int i = 0; i < steps; i++) {

        double time = i * dt;

        double velocity = model.calculateVelocity(S);

        S = S - velocity * dt;

        if (S < 0)
            S = 0;

        timeData.push_back(time);
        substrateData.push_back(S);

        std::cout
            << std::setw(12)
            << std::fixed
            << std::setprecision(4)
            << time

            << std::setw(18)
            << S
            << std::endl;
    }

    FileHandler::writeCSV(
        outputFile,
        timeData,
        substrateData
    );
}



void combinedSimulation(
    KineticsModel& normal,
    KineticsModel& competitive,
    KineticsModel& noncompetitive,
    double initialSubstrate,
    double dt,
    double totalTime
) {

    double Sn = initialSubstrate;
    double Sc = initialSubstrate;
    double Snc = initialSubstrate;

    int steps = totalTime / dt;

    std::cout << "\n========== ALL SIMULATIONS ==========\n\n";

    std::cout
        << std::setw(12) << "Time"
        << std::setw(18) << "Normal"
        << std::setw(18) << "Competitive"
        << std::setw(22) << "NonCompetitive"
        << std::endl;

    for (int i = 0; i < steps; i++) {

        double time = i * dt;

        double vn = normal.calculateVelocity(Sn);
        double vc = competitive.calculateVelocity(Sc);
        double vnc = noncompetitive.calculateVelocity(Snc);

        Sn -= vn * dt;
        Sc -= vc * dt;
        Snc -= vnc * dt;

        if (Sn < 0) Sn = 0;
        if (Sc < 0) Sc = 0;
        if (Snc < 0) Snc = 0;

        std::cout
            << std::setw(12)
            << std::fixed
            << std::setprecision(4)
            << time

            << std::setw(18)
            << Sn

            << std::setw(18)
            << Sc

            << std::setw(22)
            << Snc

            << std::endl;
    }
}



int main() {

    auto config = FileHandler::readConfig("config.txt");

    Enzyme enzyme(
        config["Km"],
        config["Vmax"],
        config["Temperature"]
    );


    MichaelisMenten normal(enzyme);

    CompetitiveInhibition competitive(
        enzyme,
        config["CompetitiveInhibitor"]
    );

    NonCompetitiveInhibition noncompetitive(
        enzyme,
        config["NonCompetitiveInhibitor"]
    );


    double initialSubstrate = config["InitialSubstrate"];
    double dt = config["TimeStep"];
    double totalTime = config["SimulationTime"];


    int choice = 0;

    while (choice != 5) {

        std::cout << "\n=====================================\n";
        std::cout << "      ENZYME KINETICS SIMULATOR\n";
        std::cout << "=====================================\n";

        std::cout << "1. Normal Michaelis-Menten\n";
        std::cout << "2. Competitive Inhibition\n";
        std::cout << "3. Noncompetitive Inhibition\n";
        std::cout << "4. Run All Simulations\n";
        std::cout << "5. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nInvalid input.\n";
            continue;
        }

// CLEAR leftover characters like '.' after valid input
std::cin.ignore(10000, '\n');

        switch(choice) {

            case 1:

                singleSimulation(
                    normal,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "normal.csv",
                    "Normal Michaelis-Menten"
                );

                break;



            case 2:

                singleSimulation(
                    competitive,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "competitive.csv",
                    "Competitive Inhibition"
                );

                break;



            case 3:

                singleSimulation(
                    noncompetitive,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "noncompetitive.csv",
                    "Noncompetitive Inhibition"
                );

                break;



            case 4:

                combinedSimulation(
                    normal,
                    competitive,
                    noncompetitive,
                    initialSubstrate,
                    dt,
                    totalTime
                );

                break;



            case 5:

                std::cout << "\nExiting simulator...\n";
                break;



            default:

                std::cout << "\nInvalid choice.\n";
        }
    }

    return 0;
}