#include <iostream>
#include "pi.hpp"
#include <cmath>

void print_cur_val(int n, float pi_it){
	std::cout << n << "te Ideration, Wert: " << pi_it << "\n";
}

void calc_pi_old(int rounds) {

	float pi = 0.0f;
	float s = 2.0f;

	// next s is the s for the round of the number n*2
	float next_s = 0.0f;
	
	for (int n = 1; n <= rounds; n++) {

		next_s = sqrt( 2 - ( 2 * sqrt( 1 - ( pow( s, 2) / 4 ) ) ) );

		pi = next_s * pow(2,n);
		s = next_s;
		print_cur_val(n, pi);

		
	};

	std::cout << "\n\n";

}


void calc_pi_new(int rounds) {

	std::cout << "the new way \n";

	float pi = 0.0f;
	float s = 2.0f;

	// next s is the s for the round of the number n*2
	float next_s = 0.0f;

	for (int n = 1; n <= rounds; n++) {

		next_s = sqrt( pow(s, 2) / (2 + (2 * sqrt(1 - (pow(s, 2) / 4) ) ) ) );

		pi = next_s * pow(2, n);
		s = next_s;
		print_cur_val(n, pi);


	};
	std::cout << "\n\n";
}