
#include <stdio.h>

int main() {

	float rMatrix[4*4] = {-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 2.0f, 2.0f, 1.0f, -1.0f, -2.0f, -1.0f, 1.0f, 1.0f};

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

	float lMatrix[4 * 4] = { 0.0f };


	// ELIMINATION

	// spalte
	for (int spalte = 0; spalte < (4); spalte++) {
		//ROW
		for (int reihe = 0; reihe < 4; reihe ++) {
			
			if (spalte == reihe) { 
				lMatrix[spalte + reihe * 4] = 1.0f;
							} 
			else if (reihe < spalte) {
				lMatrix[spalte + reihe * 4] = rMatrix[spalte + reihe * 4] / rMatrix[spalte + (spalte) * 4];

			
				// spalte
				for (int z = spalte; z < 4; z++) {
						
					rMatrix[z + reihe * 4] = rMatrix[z + reihe * 4] - lMatrix[spalte + reihe * 4] * rMatrix[z + ( reihe -1) * 4];
				}
				
				
			}
			else {
				lMatrix[spalte + reihe * 4] = 0.0f;
			}
		}


			
	}

	for (int spalte = 0; spalte < 4; spalte++) {
		for (int reihe = 0; reihe < 4; reihe ++) {

			printf("%.6f ", lMatrix[spalte + reihe * 4]);

		}
		printf("\n");
	}
	

	for (int spalte = 0; spalte<4; spalte++){
		for (int reihe  = 0; reihe < 4; reihe ++) {

			printf("%.6f ", rMatrix[spalte + reihe * 4]);

		}
		printf("\n");
	}
	return 0;
}
