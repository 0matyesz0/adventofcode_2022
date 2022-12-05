#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

void FirstPartOne() {
    // === Part One ===
    //std::cout << "Hello World!\n";
    //std::string caloriesInput;
    //std::ifstream inputFile("../inputs/1.txt");
    //std::vector<int> elfCaloriesSums;
    //int temporarySum = 0;
    //int max = 0;
    //while (std::getline(inputFile, caloriesInput)) {
    //    if (caloriesInput.length()) {
    //        temporarySum += std::stoi(caloriesInput);
    //    } else {
    //        elfCaloriesSums.push_back(temporarySum);
    //        if (max < temporarySum) {
    //            max = temporarySum;
    //        }
    //        temporarySum = 0;
    //    }
    //}
    //std::cout << max << std::endl; // part 1 answer: 69281
    // === Part One ===
}

void FirstPartTwo() {

    // === Part Two ===
    std::string caloriesInput;
    std::ifstream inputFile("../inputs/1.txt");
    std::vector<int> elfCaloriesSums;
    int temporarySum = 0;
    int max = 0;
    int sumOfTheTopThreeCalories = 0;

    while (std::getline(inputFile, caloriesInput)) {
        if (caloriesInput.length()) {
            temporarySum += std::stoi(caloriesInput);
        }
        else {
            elfCaloriesSums.push_back(temporarySum);
            if (max < temporarySum) {
                max = temporarySum;
            }
            temporarySum = 0;
        }
    }
    int maxSum = 0;
    for (int i = 0; i < 3; i++)
    {
        int currentMax = *std::max_element(elfCaloriesSums.begin(), elfCaloriesSums.end());
        maxSum += currentMax;
        elfCaloriesSums.erase(std::remove(elfCaloriesSums.begin(), elfCaloriesSums.end(), currentMax), elfCaloriesSums.end());
    }

    std::cout << maxSum << std::endl;
    // === Part Two ===
}