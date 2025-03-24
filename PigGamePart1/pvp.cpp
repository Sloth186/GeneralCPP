#include <iostream>
#include <thread>

#include "Die.h"

Die redDie(6);
Die blueDie(6);

int rollDice() {
	int redRoll = redDie.roll();
	int blueRoll = blueDie.roll();

	std::printf("\t%d, %d\n", redRoll, blueRoll);

	if (redRoll == 1 && blueRoll == 1) {
		std::printf("\tDouble 1's!\n");
		return 25;
	}
	if (redRoll == 1 || blueRoll == 1)
		return 0;
	if (redRoll == blueRoll) {
		std::printf("\tDoubles!\n");
		return 4 * redRoll;
	}
	return redRoll + blueRoll;
}

void playerTurn(int &score) {
	int turnScore = 0, playerInput, roll;
	
	do {
		std::printf(" Turn score: %d\n 1 - Roll\n 2 - Hold\n 3 - Quit\n  >> ", turnScore);
		std::cin >> playerInput;

		switch (playerInput) {
			case 1:
				roll = rollDice();
			if (roll == 0) {
				std::printf("\tBummer, you rolled one 1.\n");
				turnScore = 0;
			} else {
				std::printf("\tYou rolled %d!\n\n", roll);
				turnScore += roll;
				break;
			}
			case 2:
				if (turnScore == 0)
					std::printf("\tYou gained no points.\n");
				else {
					score += turnScore;
					std::printf("\tYou gained %d points!\n", turnScore);
				}
			std::printf("\tYour turn ends!\n--------------------\n");
			break;
			case 3:
				exit(1);
			default:
				printf("\tInvalid input.\n\n");
		}
	} while (playerInput != 2 && playerInput != 3 && turnScore != 0);
}

int main() {
	srand(time(nullptr));

	int playerOne = 0, playerTwo = 0;

	while (playerOne < 100 && playerTwo < 100) {
		std::printf("Player 1 score: %d\t\tPlayer 2 score: %d\n\nPLAYER ONE TURN\n", playerOne, playerTwo);
		playerTurn(playerOne);
		if (playerOne < 100) {
			std::printf("Player 1 score: %d\t\tPlayer 2 score: %d\n\nPLAYER TWO TURN\n", playerOne, playerTwo);
			playerTurn(playerTwo);
		}
	}

	std::printf("Player 1 score: %d\t\tPlayer 2 score: %d\n\n", playerOne, playerTwo);

	if (playerOne >= 100)
		std::printf("Player ONE won!");
	else if (playerTwo >= 100)
		std::printf("Player TWO won!");
}