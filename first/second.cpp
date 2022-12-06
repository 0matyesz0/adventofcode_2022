#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

std::vector<std::string> SplitLineIntoChoices(const std::string& lineInput) {
	std::stringstream lineStr(lineInput);
	std::string part;
	std::vector<std::string> choices;

	while (std::getline(lineStr, part, ' ')) {
		choices.push_back(part);
	}

	return choices;
}

// A/X: Rock
// B/Y: Paper
// C/Z: Scissor
// --------------------------
// A Beats C -> X Beats C --> B beats X
// B Beats A -> Y Beats A --> C beats Y
// C Beats B -> Z Beats B --> A beats Z
int CalculateScoreBasedOnRoundOutCome(const std::string& opponentChoice, const std::string& myChoice) {
	int score = 3;
	int scoreMultiplier = 0;
	// Draw
	const bool draw1 = (opponentChoice == "A") && (myChoice == "X");
	const bool draw2 = (opponentChoice == "B") && (myChoice == "Y");
	const bool draw3 = (opponentChoice == "C") && (myChoice == "Z");
	if (draw1 || draw2 || draw3) {
		scoreMultiplier = 1;
	}

	// Wins:
	const bool win1 = (opponentChoice == "A") && (myChoice == "Y");
	const bool win2 = (opponentChoice == "B") && (myChoice == "Z");
	const bool win3 = (opponentChoice == "C") && (myChoice == "X");
	if (win1 || win2 || win3) {
		scoreMultiplier = 2;
	}

	//Looses:
	const bool lose1 = (opponentChoice == "B") && (myChoice == "X");
	const bool lose2 = (opponentChoice == "C") && (myChoice == "Y");
	const bool lose3 = (opponentChoice == "A") && (myChoice == "Z");
	if (lose1 || lose2 || lose3) {
		scoreMultiplier = 0;
	}

	return score * scoreMultiplier;
}

int CalculateScoreBasedOnMyChoice(const std::string& myChoice) {
	if (myChoice == "X")
		return 1;
	if (myChoice == "Y")
		return 2;
	if (myChoice == "Z")
		return 3;
}

void SecondPartOne() {
	std::string rpcInput;
	std::ifstream inputFile("../inputs/2.txt");
	int totalScore = 0;

	while (std::getline(inputFile, rpcInput)) {
		auto lineChoices = SplitLineIntoChoices(rpcInput);
		totalScore += CalculateScoreBasedOnMyChoice(lineChoices[1]);
		totalScore += CalculateScoreBasedOnRoundOutCome(lineChoices[0], lineChoices[1]);
	}

	std::cout << totalScore << std::endl;

}
