#include "marathon.h"

void readData(std::string names[], double miles[][NUM_DAYS], std::ifstream& inFile) {
    for (int i = 0; i < NUM_RUNNERS; i++) {
        inFile >> names[i];
        for (int j = 0; j < NUM_DAYS; j++) {
            inFile >> miles[i][j];
        }
    }
}

void calculateTotalsAndAverages(const double miles[][NUM_DAYS], double totals[], double averages[]) {
    for (int i = 0; i < NUM_RUNNERS; i++) {
        totals[i] = 0;
        for (int j = 0; j < NUM_DAYS; j++) {
            totals[i] += miles[i][j];
        }
        averages[i] = totals[i] / NUM_DAYS;
    }
}

void printResults(const std::string names[], const double miles[][NUM_DAYS], const double totals[], const double averages[]) {
    std::cout << std::left << std::setw(10) << "Name";
    for (int i = 1; i <= NUM_DAYS; i++) {
        if (i == 4) { // Apply additional spacing starting from Day 4
            std::cout << std::right << std::setw(8) << "Day" << i; // Increase setw for Day 4 and beyond
        }
        else {
            std::cout << std::right << std::setw(6) << "Day" << i;
        }
    }
    std::cout << std::right << std::setw(12) << "Total" << std::setw(12) << "Average" << std::endl; // Adjust spacing for Total and Average

    for (int i = 0; i < NUM_RUNNERS; i++) {
        std::cout << std::left << std::setw(10) << names[i];
        for (int j = 0; j < NUM_DAYS; j++) {
            if (j >= 3) { // Adjust spacing starting from the data of Day 4
                std::cout << std::right << std::setw(8) << std::fixed << std::setprecision(0) << miles[i][j];
            }
            else {
                std::cout << std::right << std::setw(6) << std::fixed << std::setprecision(0) << miles[i][j];
            }
        }
        std::cout << std::right << std::setw(12) << std::fixed << std::setprecision(0) << totals[i]
            << std::setw(12) << std::fixed << std::setprecision(2) << averages[i] << std::endl;
    }
}

int main() {
    std::string runnerNames[NUM_RUNNERS];
    double milesPerDay[NUM_RUNNERS][NUM_DAYS];
    double totalMiles[NUM_RUNNERS];
    double averageMiles[NUM_RUNNERS];

    std::ifstream inFile("runners.txt");
    if (!inFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    readData(runnerNames, milesPerDay, inFile);
    inFile.close();

    calculateTotalsAndAverages(milesPerDay, totalMiles, averageMiles);
    printResults(runnerNames, milesPerDay, totalMiles, averageMiles);

    return 0;
}
