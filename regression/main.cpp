#include <iostream>

int main() {

	// 11 values
	const int  n = 11;

	// X array
	int years[n] = {1905, 1915, 1925, 1935, 1945, 1955, 1965, 1975, 1985, 1995, 2005};

	// Y array
	float temp[n] = { 7.7f, 8.0f, 7.9f, 8.1f, 8.3f, 8.1f, 7.9f, 8.3f, 8.5f, 9.0f, 9.2f };

	// gesucht: Regressionsgerade
	// y = bx + a

	float sum_x = 0.0f;
	float sum_y = 0.0f;
	float sum_x_and_y = 0.0f;
	float sum_x_square = 0.0f;
	float avg_x = 0.0f;
	float avg_y = 0.0f;
	float cur_x = 0.0f;
	float cur_y = 0.0f;

	for (int i = 0; i < n;i++) {

		cur_x = years[i];
		cur_y = temp[i];

		sum_x += cur_x;
		sum_y += cur_y;
		sum_x_square += cur_x * cur_x;
		sum_x_and_y += cur_x * cur_y;

	};


	avg_x = sum_x * (1.0f / n);
	avg_y = sum_y * (1.0f / n);

	float b = (sum_x_and_y - (n * avg_x * avg_y)) / (sum_x_square - n * pow(avg_x, 2));
	float a = avg_y - b * avg_x;

	std::cout << "The recursion-function is: \nf(x) = " << b << " * x + " << a << "\n";


	return 0;
}