#pragma once
#include <vector>

void SecondPartOne();
void SecondPartTwo();
std::vector<std::string> SplitLineIntoChoices(const std::string& lineInput);
int CalculateScoreBasedOnRoundOutCome(const std::string& opponentChoice, const std::string& myChoice);
int CalculateScoreBasedOnRoundIndication(const std::string& opponentChoice, const std::string& indication);
int CalculateScoreBasedOnMyChoice(const std::string& myChoice);