#include "heron.hpp"
#include <iostream>
#include <cmath>

float heron(int number, int grade) {

	float result = 0.0f;
	float x = 1.0f;
	int count = 0;
	float desired_accuracy = 0.01f;
	float cur_accuracy = 1000.0f;
	std::cout << "\n";

	while (cur_accuracy > desired_accuracy) {

		count++;

		result = ((grade - 1) * pow(x, grade) + number) / (grade * pow(x, grade - 1));

		std::cout << "Step " << count << ": " << result << "\n";

		cur_accuracy = std::abs(x - result);
		x = result;

	}

	return result;
};