#include <stdio.h>
#include <math.h>

float func(float a, float b) {

	return pow(a, 2) + pow(b, 2);

}

float derivative_a(float x, float y) {

	float h = 0.001;

	return ((func(x + h, y) - func(x, y)) / (h));

}

float derivative_b(float x, float y) {

	float h = 0.001;

	return ((func(x, y + h)) - func(x, y)) / (h);

}


int main() {

	float minima_param_a = 1.0f;
	float minima_param_b = 1.0f;
	float step_size = 0.3f;
	float minima_param_a_new = 0.0f;
	float minima_param_b_new = 0.0f;
	float y = 0.0f;


	while ((fabs(derivative_a(minima_param_a, minima_param_b)) + fabs(derivative_b(minima_param_b, minima_param_b))) > 0.01f) {

		minima_param_a_new = minima_param_a - step_size * derivative_a(minima_param_a, minima_param_b);
		minima_param_b_new = minima_param_b - step_size * derivative_b(minima_param_a, minima_param_b);

		minima_param_a = minima_param_a_new;
		minima_param_b = minima_param_b_new;


	}

	printf("Your Minima is at x = %.6f and y = %.6f \n", minima_param_a, minima_param_b);

	return 0;
}