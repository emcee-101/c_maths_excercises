#include <iostream>
#include "prime_numbers.hpp"

void printVal(bool numbers[], int n){

	for (int i = 0; i < (n + 1); i++) {

		(numbers[i]) ? (std::cout << "Die Zahl "<< i << " ist eine Primzahl.\n") : (std::cout<<"");
	}
}

void printPrimeNumbers(int n) {


	bool* numbers = new bool[n+1];

	// initialization of first two values (cos 0 and 1 are no prime numbers)
	numbers[0] = false;

	if (n<0){
		numbers[1] = false;
	}

	for (int i = 2; i < (trunc((float) sqrt(n))+1); i++){
		
		for (int k = i; i < (trunc(n / i) + 1) ; k++) {

			// i * k is not a prime number
			numbers[i * k] = false;

		}
	
	}

	printVal(numbers, n);
	delete[] numbers;

};