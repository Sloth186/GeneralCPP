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

	for (auto c : input) {
		queue.emplace(c);
		stack.emplace(c);
	}

	bool flag = true;
	while (!queue.empty() && flag) {
		while (queue.front() < 'A' || (queue.front() > 'Z' && queue.front() < 'a') || queue.front() > 'z')
			queue.pop();
		while (stack.top() < 'A' || (stack.top() > 'Z' && stack.top() < 'a') || stack.top() > 'z')
			stack.pop();

		if (toupper(queue.front()) != toupper(stack.top()))
			flag = false;

		queue.pop();
		stack.pop();
	}

	if (flag)
		std::cout << "\"" << input << "\" is a palindrome\n";
	else
		std::cout << "\"" << input << "\" is not a palindrome\n";
}