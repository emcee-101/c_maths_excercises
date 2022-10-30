#include <iostream>
#include <cmath>

double calc_y(double x);

double calc_with_rect(double size_of_step, double interval_bottom, double interval_top) {


	double num = 0.0f;

	for (double i = interval_bottom; i < interval_top; i += size_of_step) {
		
		num += calc_y(i) * size_of_step;
		//std::cout << i << "^2 * " << size_of_step << "\n";
	}
	return num;


}

double calc_with_trapeze(double size_of_step, double interval_bottom, double interval_top) {


	double num = 0.0f, num2 = 0.0f;

	for (double i = interval_bottom; i < interval_top-size_of_step; i += size_of_step) {

		num2 += calc_y(i);
		//std::cout << i << " " << (num2*size_of_step) << "\n";

	}

	num = size_of_step * (num2 + ((calc_y(interval_bottom) + calc_y(interval_top)) / 2));
	return num;


}

double calc_with_simpson(double size_of_step, double interval_bottom, double interval_top) {


	// this needs to a even number, else its not gonna work
	int num_of_steps = (((interval_top - interval_bottom)/size_of_step));

	float num = 0.0f;
	float h = (interval_top-interval_bottom/num_of_steps);

	// reducing by two because two parts of the loop need to take place outside of the loop
	num_of_steps -= 2;

	// initalizing toggle to switch between multiplying by 2 and 4
	bool four = true;

	// first step
	num = calc_y(interval_bottom);
	
	for (float i = interval_bottom + size_of_step; i < interval_top - size_of_step; i += size_of_step) {
	
		four ? num += calc_y(i) * 4 : num += calc_y(i) * 2;

		four ? four = false : four = true;
		std::cout << "four: " << four << ", i = " << i << "\n";

	}

	// last step
	num += calc_y(interval_top);

	return ((h / 3.0f) * (num));


}

double calc_y(double x) {

	return x*x;

};

int main(){


	//calc_function fnc = (calc_function) new calc_function_a;



	float a = calc_with_rect(0.1f, 0, 2);
	std::cout << "rect result: " << a << "\n";

	a = calc_with_trapeze(0.01f, 0, 2);
	std::cout << "trapeze result: " << a<<"\n";

	a = calc_with_simpson(0.5f, 0, 2);
	std::cout << "simpson result: " << a << "\n";

	return 0;
}