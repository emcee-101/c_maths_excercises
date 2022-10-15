#include <iostream>
#include "prime_numbers.hpp"
#include <vector>

void printVal(std::vector<int> &nums){

	std::cout << nums.size() << "\n";

}

std::vector<int> getPrimeNumbers(int n) {

	std::vector<int> numbers(0);

	printVal(numbers);

	for (int h = 2; h < n + 1; h++) {

		numbers.push_back(h);

	}

	printVal(numbers);

	for (int i = 2; i < (trunc(sqrt(n))+1); i++){
		
		for (int k = i; i < (trunc(n / i) + 1) ; k++) {

			// i * k is not a prime number

		}
	
	}

};