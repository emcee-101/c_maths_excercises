#include <iostream>
#include <cmath>

const int n = 3; // Change this to the size of your square matrix A and vector b


bool weakDiagonalCriteriaReached(double A[n][n]){

    for (int i = 0; i < n; i++) {

        double tempSum = 0.0f;

        for (int j = 0; j < n; j++) {

            if(i!=j) tempSum += std::abs(A[i][j]);

        }

        if(!(tempSum <= std::abs(A[i][i]))){

                //std::cout << "returning false >:()";
                return false;
        } ;

    }

    //std::cout << "returned true on that criteria thingy";
    return true;
}


// Function to perform the Jacobi method
void jacobiMethod(double A[n][n], double b[n], double x[n], int maxIterations, double tolerance) {
    


    double temp[n] = {0.0f};
    double sumTemp = 0.0f;
    int count = 0;

    if(weakDiagonalCriteriaReached(A)){
        std::cout << "Diese berechnung wird konvergieren\n\n";
    }

    bool runFurther = true;

    while( runFurther ){


        for (int i = 0; i < n; i++) {

            sumTemp = 0.0f;

            for (int j = 0; j < n; j++) {

                if (j != i) {
                    sumTemp += A[i][j] * x[j];
                }
            }

            temp[i] = (1 / A[i][i]) * (b[i] - sumTemp);
            //std::cout << temp[i] << std::endl;
        }


        if(count != 0 && ((std::abs(x[0] - temp[0]) < tolerance) && (std::abs(x[1] - temp[1]) < tolerance) && (std::abs(x[2] - temp[2]) < tolerance)))
            runFurther = false;



        x[0] = temp[0];
        x[1] = temp[1];
        x[2] = temp[2];

        count ++;
    }

    std::cout << "Sind das die Werte die du suchst?? x1="<<x[0]<<" x2="<<x[1]<<" x3="<<x[2]<<"\n";
}

int main() {
    // Example matrix A and vector b
    double A[n][n] = {
        {3, 1, 0},
        {1, 3, 1},
        {0, 1, 3}
    };

    double b[n] = { 1, 5, 7 };

    double x[n] = { 0, 0, 0}; // Initial guess for x

    int maxIterations = 1000;
    double tolerance = 0.01f;

    jacobiMethod(A, b, x, maxIterations, tolerance);

    std::cout << std::endl;

    return 0;
}
