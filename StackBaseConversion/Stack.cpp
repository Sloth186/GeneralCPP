/*
	Homework 14: a stack of integers used to convert a positive base 10 integer to base 2
	Author: Barbara Z. Johnson and Shen Rothermel
	Date:  October 11, 2024
	Revised:

*/

#include <iostream>

using namespace std;

const int n = 16;

/*
	Stack class with an array implementation, using classic Stack methods
*/

class Stack {
		int top_i;
		int arr[n];   // set up to handle a short integer of bits
		int num_ele;

	public:
		Stack() {
			top_i = -1;
			num_ele = 0;
			for (int i = 0; i < n; i++)
				arr[i] = 0;

		} // basic constructor and initializer

		// should return the number of elements in the Stack
		int size() {
			return num_ele;
		} // get size

		// return true if the Stack has no elements.  False otherwise
		bool isEmpty() {
			return num_ele == 0;
		}

		// add num to the Stack, adjusting other fields as appropriate
		// return false if you can't add an item (when would this be true???)
		// return true if the addition was successful
		bool push(int num) {
			if (size() == n)
				return false;

			++top_i;
			arr[top_i] = num;
			++num_ele;
			return true;
		} // push


		// remove and return the item at the top of the Stack
		// unlike the std library Stack<>, we return the integer too
		int pop() {
			if (isEmpty())
				return -1;

			int temp = arr[top_i];
			--top_i;
			--num_ele;
			return temp;
		} // pop changes the stack

       // returns value at top without changing the Stack
		int top() {
			if (isEmpty())
				return -1;
			return arr[top_i];
		}

}; //  Stack class


int main() {
	int userInput;

	// Prompt user for number
	std::cout << "Enter a number between -32,767 and 32768: ";
	std::cin >> userInput;

	// Validate user input
	if (userInput < -32767 || userInput > 32768) {
		std::cout << "You chose a number outside of the supported range." << std::endl;
		exit(1);
	}

	// Set up stack
	Stack stack;
	int number = userInput;

	// Check if user input is a negative number
	bool isNegative = number < 0;
	if (isNegative)
		number *= -1;

	// Do repeated division and push the 0 or 1 remainder to the stack
	while (number > 0) {
		stack.push(number % 2);
		number /= 2;
	}
	// Fill the remaining bits with 0's
	while (stack.size() < 16)
		stack.push(0);

	if (isNegative) {
		// Set up stack to get negative binary representation
		Stack negStack;
		int sum;
		int carry;

		// Pop the stack, pushing the complement of each digit to the negative stack
		while (!stack.isEmpty())
			negStack.push(!stack.pop());

		// Pop and push the first digit, adding 1 to it
		sum = negStack.pop() + 1;
		if (sum > 1) {
			carry = 1;
			sum = 0;
		} else carry = 0;
		stack.push(sum);

		// Pop and push the remaining digits, adding any necessary carries
		while (!negStack.isEmpty()) {
			sum = negStack.pop() + carry;
			if (sum > 1) {
				carry = 1;
				sum = 0;
			} else carry = 0;
			stack.push(sum);
		}
	}

	// Print the decimal number and corresponding binary number
	std::cout << "Decimal: " << userInput << std::endl;
	std::cout << "Binary: ";
	while (!stack.isEmpty())
		std::cout << stack.pop();
	std::cout << std::endl;

	return 0;
}