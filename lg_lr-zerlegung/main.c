
#include <stdio.h>

int main() {

	float lgMatrix[4*4] = {-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 2.0f, 2.0f, 1.0f, -1.0f, -2.0f, -1.0f, 1.0f, 1.0f};

	float resVector[4] = {1.0f, 2.0f, 3.0f, 4.0f};
	
	/*
	                lgMatrix:
					- ist in Row Major Order
	 				- Gleichungssystem mir 4 Zeilen und jeweils 4 Faktoren
					- multipliziert mit Vektor xT = {x1,x2,x3,x4} ergibt sich aus ihr resVector
	*/


	/*
					Vektor xT Lösung:
						/ 1 \
						| 1 |		Doch wie kommen wir da hin?
						| 3 |		LR-Substitution...
						\ 4 /
	*/

	float rMatrix[4 * 4] = { 0.0f };
	float lMatrix[4 * 4] = { 0.0f };

	for (int element = 0; element <= 16; element++) {
		// copy
		rMatrix[element] = lgMatrix[element];
		lMatrix[element] = lgMatrix[element];
	};

	// ELIMMINTATION

	int posNeededForSplitR[6] = {1, 2, 3, 6, 7, 11};
	int posNeededForSplitL[6] = {4, 8, 9, 12, 13, 14};

	float l2 = lgMatrix[0 + 1 * 4] / lgMatrix[0 + 0 * 4];
	float l3 = lgMatrix[0 + 2 * 4] / lgMatrix[0 + 0 * 4];

	for (int element = 0; element <= 4; element++) {

		// produce the zeroes
		lMatrix[element + 1 * 4] = lMatrix[element + 1 * 4] - l2 * lgMatrix[element + 0 * 4];
		lMatrix[element + 2 * 4] = lMatrix[element + 2 * 4] - l3 * lgMatrix[element + 0 * 4];

	};


	for (int i = 0; i<4; i++){
		for (int y  = 0; y < 4; y++) {

			printf("%.6f", lMatrix[y + i * 4]);

		}
		printf("\n");
	}
	return 0;
}