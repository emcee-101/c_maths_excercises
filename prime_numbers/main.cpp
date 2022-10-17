#include <iostream>
#include "prime_numbers.hpp"

int main() {

	int n = 0;
	// input int n
	std::cin >> n;

	// call function to generate prime numbers
	printPrimeNumbers(n);

	return 0;
}