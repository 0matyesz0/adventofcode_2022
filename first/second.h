#pragma once
#include <vector>

void SecondPartOne();
std::vector<std::string> SplitLineIntoChoices(const std::string& lineInput);
int CalculateScoreBasedOnRoundOutCome(const std::string& opponentChoice, const std::string& myChoice);
int CalculateScoreBasedOnMyChoice(const std::string& myChoice);