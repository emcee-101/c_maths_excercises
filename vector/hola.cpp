#include<stdio.h>
#include "CVector.hpp"

int main(){

    printf("buenas dias :)\n");
    

    float[4] floatValues = {4,2,3,1};
    CVector epicVector = new CVector(floatValues);
    float dotProduct = epicVector.Dot3();
    
    printf("%.6f", dotProduct);

    return 0;
}