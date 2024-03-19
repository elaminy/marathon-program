#pragma once
#ifndef MARATHON_H
#define MARATHON_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

void readData(std::string names[], double miles[][NUM_DAYS], std::ifstream& inFile);
void calculateTotalsAndAverages(const double miles[][NUM_DAYS], double totals[], double averages[]);
void printResults(const std::string names[], const double miles[][NUM_DAYS], const double totals[], const double averages[]);

#endif