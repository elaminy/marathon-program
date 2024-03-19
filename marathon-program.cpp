#include "marathon.h"

struct Runner {
    std::string name;
    double miles[NUM_DAYS];
    double total;
    double average;
};

void readData(Runner runners[], std::ifstream& inFile) {
    for (int i = 0; i < NUM_RUNNERS; i++) {
        inFile >> runners[i].name;
        for (int j = 0; j < NUM_DAYS; j++) {
            inFile >> runners[i].miles[j];
        }
    }
}

void calculateTotalsAndAverages(Runner runners[]) {
    for (int i = 0; i < NUM_RUNNERS; i++) {
        runners[i].total = 0;
        for (int j = 0; j < NUM_DAYS; j++) {
            runners[i].total += runners[i].miles[j];
        }
        runners[i].average = runners[i].total / NUM_DAYS;
    }
}

void printResults(const Runner runners[]) {
    std::cout << std::left << std::setw(10) << "Name";
    for (int i = 1; i <= NUM_DAYS; i++) {
        if (i == 4) { // Apply additional spacing starting from Day 4
            std::cout << std::right << std::setw(7) << "Day" << i; // Increase setw for Day 4 and beyond
        }
        else {
            std::cout << std::right << std::setw(5) << "Day" << i;
        }
    }
    std::cout << std::right << std::setw(10) << "Total" << std::setw(12) << "Average" << std::endl; // Adjust spacing for Total and Average

    for (int i = 0; i < NUM_RUNNERS; i++) {
        std::cout << std::left << std::setw(10) << runners[i].name;
        for (int j = 0; j < NUM_DAYS; j++) {
            if (j >= 3) { // Adjust spacing starting from the data of Day 4
                std::cout << std::right << std::setw(7) << std::fixed << std::setprecision(0) << runners[i].miles[j];
            }
            else {
                std::cout << std::right << std::setw(5) << std::fixed << std::setprecision(0) << runners[i].miles[j];
            }
        }
        std::cout << std::right << std::setw(10) << std::fixed << std::setprecision(0) << runners[i].total
            << std::setw(12) << std::fixed << std::setprecision(2) << runners[i].average << std::endl;
    }
}

int main() {
    Runner runners[NUM_RUNNERS];

    std::ifstream inFile("runners.txt");
    if (!inFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    readData(runners, inFile);
    inFile.close();

    calculateTotalsAndAverages(runners);
    printResults(runners);

    return 0;
}
