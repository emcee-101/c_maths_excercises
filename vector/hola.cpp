#include<stdio.h>
#include "CVector.hpp"

int main(){

    printf("buenas dias :)\n");
    
    std::array<float, CVector::s_Dimensions> floatValues = {1,2,3,4};
    CVector *epicVector = new CVector(floatValues);

    std::array<float, CVector::s_Dimensions> floatValues2 = { 3,2,1,4 };
    CVector* unEpicVector = new CVector(floatValues2);

    float dotProduct = epicVector->Dot3(*unEpicVector);
    
    printf("%.6f", dotProduct);

    return 0;
}