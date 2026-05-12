#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

#include "../include/enzyme.h"
#include "../include/kinetics_model.h"
#include "../include/file_handler.h"
#include "../include/lineweaver_burk.h"

void saveSimulationCSV(
    KineticsModel& model,
    double initialSubstrate,
    double dt,
    double totalTime,
    const std::string& outputFile
) {

    std::vector<double> timeData;
    std::vector<double> substrateData;

    double S = initialSubstrate;

    int steps = totalTime / dt;

    for (int i = 0; i < steps; i++) {

        double time = i * dt;

        double velocity = model.calculateVelocity(S);

        S = S - velocity * dt;

        if (S < 0)
            S = 0;

        timeData.push_back(time);
        substrateData.push_back(S);
    }

    FileHandler::writeCSV(
        outputFile,
        timeData,
        substrateData
    );
}

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
    std::vector<double> normal_velocity;
    std::vector<double> competitive_velocity;
    std::vector<double> noncompetitive_velocity;
    


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

    double Vmax, Km, initialSubstrate, dt;
    double competitiveInhibitor, nonCompetitiveInhibitor, totalTime;

    std::cout << "\n=== Enter Simulation Parameters ===\n";

    std::cout << "Enter Vmax: ";
    std::cin >> Vmax;

    std::cout << "Enter Km: ";
    std::cin >> Km;

    std::cout << "Enter competitive inhibitor concentration: ";
    std::cin >> competitiveInhibitor;

    std::cout << "Enter noncompetitive inhibitor concentration: ";
    std::cin >> nonCompetitiveInhibitor;

    std::cout << "Enter initial substrate concentration: ";
    std::cin >> initialSubstrate;

    std::cout << "Enter timestep dt: ";
    std::cin >> dt;

    std::cout << "Enter total simulation time: ";
    std::cin >> totalTime;

    Enzyme enzyme(Km, Vmax, 37.0);

    MichaelisMenten normal(enzyme);

    CompetitiveInhibition competitive(
        enzyme,
        competitiveInhibitor
    );

    NonCompetitiveInhibition noncompetitive(
        enzyme,
        nonCompetitiveInhibitor
    );

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

        std::cin.ignore(10000, '\n');

        switch(choice) {

            case 1:

                singleSimulation(
                    normal,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "results/normal.csv",
                    "Normal Michaelis-Menten"
                );

                system("py plot_normal.py");
                system("py plot_lineweaver_normal.py");
                break;

            case 2:

                singleSimulation(
                    competitive,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "results/competitive.csv",
                    "Competitive Inhibition"
                );

                system("py plot_competitive.py");
                system("py plot_lineweaver_competitive.py");
                break;

            case 3:

                singleSimulation(
                    noncompetitive,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "results/noncompetitive.csv",
                    "Noncompetitive Inhibition"
                );

                system("py plot_noncompetitive.py");
                system("py plot_lineweaver_noncompetitive.py");
                break;

            case 4:

                saveSimulationCSV(
                    normal,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "results/normal.csv"
                );

                saveSimulationCSV(
                    competitive,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "results/competitive.csv"
                );

                saveSimulationCSV(
                    noncompetitive,
                    initialSubstrate,
                    dt,
                    totalTime,
                    "results/noncompetitive.csv"
                );

                combinedSimulation(
                    normal,
                    competitive,
                    noncompetitive,
                    initialSubstrate,
                    dt,
                    totalTime
                );

                system("py plot_combined.py");
                system("py plot_lineweaver_combined.py");
                system("py plot_velocity.py");
            break;

            case 5:

                std::cout << "\nExiting simulator...\n";
                break;

            default:

                std::cout << "\nInvalid choice.\n";
        }
    }

    // NORMAL

    std::vector<double> normal_substrate;
    std::vector<double> normal_velocity;

    double S1 = 5.0;

    for (int i = 0; i < 300; i++) {

        double velocity = normal.calculateVelocity(S1);

        normal_substrate.push_back(S1);
        normal_velocity.push_back(velocity);

        S1 = S1 - velocity * dt;

        if (S1 < 0.0001)
            S1 = 0.0001;
    }


    // COMPETITIVE

    std::vector<double> competitive_substrate;
    std::vector<double> competitive_velocity;

    double S2 = 5.0;

    for (int i = 0; i < 300; i++) {

        double velocity = competitive.calculateVelocity(S2);

        competitive_substrate.push_back(S2);
        competitive_velocity.push_back(velocity);

        S2 = S2 - velocity * dt;

        if (S2 < 0.0001)
            S2 = 0.0001;
    }


    // NONCOMPETITIVE

    std::vector<double> noncompetitive_substrate;
    std::vector<double> noncompetitive_velocity;

    double S3 = 5.0;

    for (int i = 0; i < 300; i++) {

        double velocity = noncompetitive.calculateVelocity(S3);

        noncompetitive_substrate.push_back(S3);
        noncompetitive_velocity.push_back(velocity);

        S3 = S3 - velocity * dt;

        if (S3 < 0.0001)
            S3 = 0.0001;
    }


    // INVERSE VALUES

    std::vector<double> invS_normal =
        LineweaverBurk::inverseSubstrate(normal_substrate);

    std::vector<double> invV_normal =
        LineweaverBurk::inverseVelocity(normal_velocity);


    std::vector<double> invS_comp =
        LineweaverBurk::inverseSubstrate(competitive_substrate);

    std::vector<double> invV_comp =
        LineweaverBurk::inverseVelocity(competitive_velocity);


    std::vector<double> invS_noncomp =
        LineweaverBurk::inverseSubstrate(noncompetitive_substrate);

    std::vector<double> invV_noncomp =
        LineweaverBurk::inverseVelocity(noncompetitive_velocity);


    // SAVE CSV

    std::ofstream lbFile("results/lineweaver_burk.csv");

    lbFile << "InvS_Normal,InvV_Normal,"
           << "InvS_Competitive,InvV_Competitive,"
           << "InvS_Noncompetitive,InvV_Noncompetitive\n";

    for (int i = 0; i < 300; i++) {

        lbFile
            << invS_normal[i] << ","
            << invV_normal[i] << ","

            << invS_comp[i] << ","
            << invV_comp[i] << ","

            << invS_noncomp[i] << ","
            << invV_noncomp[i]

            << "\n";
    }

    lbFile.close();

    return 0;
}

