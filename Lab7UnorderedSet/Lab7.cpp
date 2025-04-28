//
// Created by scrot on 4/23/2025.
//

#include <fstream>
#include <iostream>
#include <unordered_set>

int main() {
	std::string inputFile;
	std::cout << "Enter input file name: ";
	std::cin >> inputFile;

	std::ifstream input;

	input.open(inputFile);

	if (input.fail()) {
		std::cout << "Input file does not exist" << std::endl;
		exit(1);
	}

	std::cout << "Input file opened" << std::endl;

	std::unordered_set<int> numbers;
	int num;
	while (input >> num)
		numbers.insert(num);

	std::cout << "Numbers read" << std::endl;

	input.close();

	std::cout << "Input file closed" << std::endl;

	std::string outputFile;
	std::cout << "Enter output file name: ";
	std::cin >> outputFile;

	std::ofstream output;

	output.open(outputFile);

	std::cout << "Output file opened" << std::endl;

	for (auto it : numbers)
		output << it << " ";
	output << std::endl;

	output.close();

	std::cout << "Output file closed" << std::endl;
}
