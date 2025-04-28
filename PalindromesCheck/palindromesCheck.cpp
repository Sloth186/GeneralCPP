//
// Created by scrot on 4/8/2025.
//

#include <iostream>
#include <queue>
#include <stack>
#include <string>

int main() {
	std::queue<char> queue;
	std::stack<char> stack;

	std::string input;
	std::cout << "Enter string: ";
	std::getline(std::cin, input);

	for (const auto c : input) {
		if (std::isalpha(c)) {
			queue.emplace(std::toupper(c));
			stack.emplace(std::toupper(c));
		}
	}

	bool flag = true;
	while (flag && !queue.empty()) {
		if (queue.front() != stack.top())
			flag = false;

		queue.pop();
		stack.pop();
	}

	if (flag)
		std::cout << "\"" << input << "\" is a palindrome\n";
	else
		std::cout << "\"" << input << "\" is not a palindrome\n";
}