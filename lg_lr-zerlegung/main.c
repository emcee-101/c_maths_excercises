
#include <stdio.h>


// forward declare the functions
int changeMatrixVal(float* Matrix, int row, int collumn, float newVal);
int calcRow(float* rMatrix, int row, float factor, int referenceRow);
float accessMatrixVal(float* Matrix, int row, int collumn);
void readMatrix(float* Matrix);
void getIdentityMatrix(float* Matrix);

int calcRow(float* rMatrix, int row, float factor, int referenceRow) { 
	
	for (int collumn = 0; collumn < 4; collumn++) {

		changeMatrixVal(rMatrix, row, collumn, accessMatrixVal(rMatrix, row, collumn) - (factor * accessMatrixVal(rMatrix, referenceRow, collumn)));
	
	}
	
	return 0;

};

float accessMatrixVal(float* Matrix, int row, int collumn){

	return Matrix[collumn + row * 4];

}

int changeMatrixVal(float* Matrix, int row, int collumn, float newVal) {

	Matrix[collumn + row * 4] = newVal;

	return 0;

}

void readMatrix(float* Matrix) {


	for (int reihe = 0; reihe < 4; reihe++) {
		for (int spalte = 0; spalte < 4; spalte++) {

			printf("%.6f ", accessMatrixVal(Matrix,reihe,spalte));

		}
		printf("\n");
	}

};

void readVector(float* Vector) {

	for (int reihe = 0; reihe < 4; reihe++) {

		printf("%.6f ", Vector[reihe]);
		printf("\n");
	}

}

void getIdentityMatrix(float* Matrix){
	
	for (int spalte = 0; spalte < 4; spalte+= 1) {
		for (int reihe = 0; reihe < 4; reihe += 1) {
			
			//printf("hello %d %d \n", spalte, reihe);
			
			if (reihe == spalte) {
				
				changeMatrixVal(Matrix, reihe, spalte, 1);
				
			}

		}
		printf("\n");
	}
}

float calcFactor(float valToBeChanged, float referenceNum) {

	return valToBeChanged / referenceNum;

};

int main() {
	
	// define the vals
	float rMatrix[4 * 4] = {-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 2.0f, 2.0f, 1.0f, -1.0f, -2.0f, -1.0f, 1.0f, 1.0f};	// the original matrix and also the space for the partly resolved matrix
	float lMatrix[4 * 4] = { 0.0f };	// the maxtrix with the factors
	float bVector[4] = { 1,2,3,4 };		// the "result" vector
	float yVector[4] = { 0.0f };		// the unknown values
	float xVector[4] = { 0.0f };		// the final result, the unknown values of the original system of equations
	
	// self explanatory
	getIdentityMatrix(lMatrix);
	

	// Get Part-Matrixes L and U (here: "l" and "r" Matrixes - left and right) (also "reihe" = "row" in german)
	for (int step = 1; step < 4; step++) {

		for (int reihe = step; reihe < 4; reihe++) {

			// calc lM wert
			changeMatrixVal(lMatrix, reihe, step - 1, calcFactor(accessMatrixVal(rMatrix, reihe, step - 1), accessMatrixVal(rMatrix, step-1, step-1)));

			
			calcRow(rMatrix, reihe, accessMatrixVal(lMatrix, reihe, step-1), step-1);

			//printf("Factor %.6f\n", accessMatrixVal(lMatrix, reihe, step - 1));
			//readMatrix(rMatrix);
			//printf("\n");
		}
	}

	float temp = 0.0f;

	// Forward substitution
	for (int row = 0; row < 4; row++) {
	
		for (int j = 0; j <= (row); j++) {

			temp += accessMatrixVal(lMatrix, row, j) * yVector[j];
			
		}
		
		yVector[row] = 1 / accessMatrixVal(lMatrix, row, row) * (bVector[row] - temp );
		temp = 0.0f;
	
	}

	// Backward Substitution
	for (int row = 4-1; row >= 0; row--) {

		for (int j = row+1; j < 4; j++) {

			temp += accessMatrixVal(rMatrix, row, j) * xVector[j];

		}

		xVector[row] = 1 / accessMatrixVal(rMatrix, row, row) * (yVector[row] - temp);
		temp = 0.0f;

	}

	printf("Your rMatrix, Sire:\n");
	readMatrix(rMatrix);
	printf("\n\nYour lMatrix, Sire:\n");
	readMatrix(lMatrix);
	printf("\n\nYour yVector, Sire:\n");
	readVector(yVector);

	printf("\n\n\n\nThe Final Results \"xVector\", Sire:\n");
	readVector(xVector);

	return 0;
}
