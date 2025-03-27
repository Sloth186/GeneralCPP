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

int main() {
	srand(time(nullptr));

	int playerScore = 0, computerScore = 0;
	int turnScore, playerInput, roll;

	while (playerScore < 100 && computerScore < 100) {
		turnScore = 0;
		std::printf("Player score: %d\t\tComputer score: %d\n\nYOUR TURN\n", playerScore, computerScore);

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
						playerScore += turnScore;
						std::printf("\tYou gained %d points!\n", turnScore);
					}
					std::printf("\tYour turn ends!\n--------------------\n");
					break;
				case 3:
					exit(1);
				default:
					printf("\tInvalid input.\n\n");
			}
		} while (playerInput != 2 && turnScore != 0);

		if (playerScore < 100) {
			turnScore = 0;
			std::printf("COMPUTER TURN\n");
			for (int i = 0; i < 4; ++i) {
				std::printf(" Turn score: %d\n", turnScore);
				std::printf(" Computer chooses to roll.\n");

				roll = rollDice();
				if (roll == 0) {
					std::printf("\tBummer, the computer rolled a 1.\n");
					turnScore = 0;
					break;
				}
				std::printf("\tComputer rolled %d!\n\n", roll);
				turnScore += roll;
			}
			if (turnScore == 0) {
				std::printf("\tComputer gained no points.\n\n");
			} else {
				std::printf(" Computer chooses to hold.\n");
				computerScore += turnScore;
				std::printf("\tComputer gained %d points!\n\n", turnScore);
			}
			std::printf("\tComputer's turn ends!\n--------------------\n");
		}
	}

	std::printf("Player score: %d\t\tComputer score: %d\n\n", playerScore, computerScore);

	if (playerScore >= 100)
		std::printf("You won!");
	else if (computerScore >= 100)
		std::printf("You lost!");
}