#include <iostream>
#include "heron.hpp"


int main(char* args[]) {

	std::cout << "Greetings!!! \n";

	std::cout << "What is the number you want to know the root of? \n";

	int a = 0;
	std::cin >> a;

	std::cout << "What is the grade of the root you wanna know? \n";

	int n = 0;
	std::cin >> n;

	float result = heron(a, n);
	std::cout << "\nYour result is: " << result << "! :)";

	return 0;

}