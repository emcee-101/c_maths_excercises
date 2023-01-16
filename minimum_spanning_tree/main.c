#include <stdio.h>

int graph[6][6] = { {10000,	3,		10000,	6,		10000,	3}, {3,		10000,	2,		5,		5,		1}, {10000, 2,		10000,	1,		9,		6}, {6,		5,		1,		10000,	2,		4}, {10000, 5,		9,		2,		10000,	1}, {3,		1,		6,		4,		1,		10000} };
int addedVertexes[20] = { 1, 10000 };

// simple linear search
int checkIfIncludedInArray(int* array, int arraySize, int checkForThisValue) {

	for (int i = 0; i < arraySize; i++) {

		if (array[i] == checkForThisValue) {

			return 1;

		}

	}

	return 0;

}

int chooseNextVertex(int* existingVertexes, int iteration){

	int tempAddedVertex = 0;
	int tempAddedConVertex = 0;
	int tempAddedWeight = 0;
	int foudSomethin = 0;
	
	for (int vertex = 0; vertex < 6; vertex++) {
			for (int conVertex= 0; conVertex < 6; conVertex++) {
				if (graph[vertex][conVertex] != 10000)
					if(0==checkIfIncludedInArray(existingVertexes, 20, conVertex)){
				
						if(tempAddedVertex == 0 || graph[vertex][conVertex] < tempAddedWeight) {
						
							tempAddedVertex = vertex;
							tempAddedConVertex = conVertex;
							tempAddedWeight = graph[vertex][conVertex];
							foudSomethin = 1;

						}
					}
			}
	}

	if (foudSomethin == 1){
		printf("added vertex number: %i and %i \n", tempAddedVertex, tempAddedConVertex);
		existingVertexes[iteration] = tempAddedConVertex;
		return tempAddedWeight;
	}
	else
		return 0;

}

int main() {

	
	int running = 1;


	int curWeight = 0;
	
	int iteration = 0;

	// Algorithm of Prim

	// choose start - like 1, doesnt matter
	

	while (running) {

		// choose minimum
		// add to array of values

		// wenn alle Konten enthalten -> running = 0;

		int addWeight = chooseNextVertex(addedVertexes, iteration);
		curWeight += addWeight;
		iteration++;
		if (addWeight == 0) {
			running = 0;
		}
	}

	printf("The weight: %i", curWeight);

	return 0;
}