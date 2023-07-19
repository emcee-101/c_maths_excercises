
#include <stdio.h>

// JACOBI

// wanted to use macro for the number of rows (since we are using symmetrical matrixes and vectors here), but it wont work
// #define ROWS 4;


// forward declare the helping functions
int changeMatrixVal(float* Matrix, int row, int collumn, float newVal);
int calcRow(float* rMatrix, int row, float factor, int referenceRow);
float accessMatrixVal(float* Matrix, int row, int collumn);
void readMatrix(float* Matrix);
void getIdentityMatrix(float* Matrix);


float accessMatrixVal(float* Matrix, int row, int collumn){

	return Matrix[collumn + row * 3];

}

int changeMatrixVal(float* Matrix, int row, int collumn, float newVal) {

	Matrix[collumn + row * 3] = newVal;

	return 0;

}

void readMatrix(float* Matrix) {


	for (int reihe = 0; reihe < 3; reihe++) {
		for (int spalte = 0; spalte < 3; spalte++) {

			printf("%.6f ", accessMatrixVal(Matrix,reihe,spalte));

		}
		printf("\n");
	}

};

void readVector(float* Vector) {

	for (int reihe = 0; reihe < 3; reihe++) {

		printf("%.6f ", Vector[reihe]);
		printf("\n");
	}

}

void getIdentityMatrix(float* Matrix){
	
	for (int spalte = 0; spalte < 3; spalte+= 1) {
		for (int reihe = 0; reihe < 3; reihe += 1) {
			
			//printf("hello %d %d \n", spalte, reihe);
			
			if (reihe == spalte) {
				
				changeMatrixVal(Matrix, reihe, spalte, 1);
				
			}

		}
		printf("\n");
	}
}

void doTheGaussSeidel(){


	// define the vals
	float linMatrix[3 * 3] = { 3.0f, 1.0f, 0.0f, 1.0f, 3.0f, 1.0f, 0.0f, 1.0f, 3.0f };
	float bVector[3] = { 1.0f,5.0f,7.0f };		// the "result" vector

	float tempResultVector[3] = { 0.0f };
	int totalRuns = 30;
	float tempVal = 0.0f;
	float tempVal2 = 0.0f;
	float tempTestAccessVal = 0.0f;

	// KONVERGENZKRITERIUM fehlt!!!


	for (int runs = 0; runs < totalRuns; runs++) {

		for (int row = 0; row < 3; row++) {

			for (int collumn = 0; collumn < (row-1); collumn++) {
			
				tempVal += accessMatrixVal(linMatrix, row, collumn) * tempResultVector[collumn];
				
			}

			for (int collumn = (row+1); collumn < 3; collumn++) {
			
				tempVal2 += accessMatrixVal(linMatrix, row, collumn) * tempResultVector[collumn];
			
			}
			

			tempResultVector[row] = 1 / accessMatrixVal(linMatrix, row, row) * (bVector[row] - tempVal - tempVal2);

			tempVal = 0.0f;
			tempVal2 = 0.0f;

		}

		//printf("\n\nThe current run sees the following result, Sire:\n");
		//readVector(tempResultVector);
	}

	printf("\n\nYour linMatrix, Sire:\n");
	readMatrix(linMatrix);

	printf("Your bMatrix, Sire:\n");
	readVector(bVector);

	printf("\n\nYour tempResultVector, Sire:\n");
	readVector(tempResultVector);
	printf("\n\n");

}

void doTheJacobi() {


	// define the vals
	float linMatrix[3 * 3] = { 3.0f, 1.0f, 0.0f, 1.0f, 3.0f, 1.0f, 0.0f, 1.0f, 3.0f };
	float bVector[3] = { 1.0f,5.0f,7.0f };		// the "result" vector
	float tempResultVector[3] = { 0.0f };
	int totalRuns = 30;
	float tempVal = 0.0f;
	float tempTestAccessVal = 0.0f;


	// KONVERGENZKRITERIUM fehlt!!!

	for (int runs = 0; runs < totalRuns; runs++) {

		for (int row = 0; row < 3; row++) {

			for (int collumn = 0; collumn < 3; collumn++) {

				if (collumn != row)
					tempVal += accessMatrixVal(linMatrix, row, collumn);

			}

			tempTestAccessVal = accessMatrixVal(linMatrix, row, row);

			tempResultVector[row] = 1 / tempTestAccessVal * (bVector[row] - tempVal * tempResultVector[row]);

			tempVal = 0.0f;

		}

		// printf("\n\nThe current run sees the following result, Sire:\n");
		// readVector(tempResultVector);
	}

	printf("Your linMatrix, Sire:\n");
	readMatrix(linMatrix);

	printf("Your bMatrix, Sire:\n");
	readVector(bVector);

	printf("\n\nYour tempResultVector, Sire:\n");
	readVector(tempResultVector);
	printf("\n\n");

}

int main() {
	
	doTheJacobi();
	doTheGaussSeidel();

	return 0;
}
