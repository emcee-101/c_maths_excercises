
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <stdbool.h>

double r2()
{
	srand(time(0));
	return (double)rand() / (double) RAND_MAX ;
}


struct path {
	int* points;
};

float getPathLength(int* graph, struct path* route) {
	
	bool stop = false;
	int curPoint = 0;
	float length = 0.0f;

	while (!stop) {

		if((route->points[curPoint] != 10000) && (route->points[curPoint++] != 10000)) {
		
			length += graph [route->points[curPoint] + route->points[curPoint++] * 6];
			curPoint++;
		
		} else stop = true;
	}
}

int main() {

	int graph[6*6] = {

							10000, 3, 5, 6, 7, 4 ,

							3, 10000, 6, 1, 4, 9 ,

							5, 6, 10000, 4, 10, 8 ,

							6, 1, 4, 10000, 7, 3 ,

							7, 4, 10, 7, 10000, 5 ,

							4, 9, 8, 3, 5, 10000 };


	float temperature = 1000.0f;
	float percentage = 100.0f;
	float gateval = 2.0f;
	float randomval = 0.0f;

	int buff1[100] = { 0 };
	int buff2[100] = { 0 };

	struct path curRoute;
	struct path newRoute;

	curRoute.points = buff1;
	newRoute.points = buff2;

	float curPathLength = 0.0f;
	float newPathLength = 0.0f;

	

	while (temperature > gateval) {

		// calc length of route
		newPathLength = getPathLength(&graph, &newRoute);

		if (newPathLength < curPathLength) {
			curPathLength = newPathLength;
			curRoute = newRoute;
		}
		else {
			percentage = exp(-newPathLength - curPathLength / temperature);
			randomval = r2();

			if (randomval < percentage) {
				curPathLength = newPathLength;
				curRoute = newRoute;

			}
		}

		// choose new round
		// get New ROute
		int buffx[100];
		newRoute.points = buffx;

		temperature = temperature / 2;

	}




	return 0;
}

