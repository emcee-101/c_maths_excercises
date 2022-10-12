#include "CVector.h"
#include <cmath>

void CVector::Set(int _Index, float _Value){

    this->m_Values[_Index] = _Value;

};

void CVector::Set(CVector& _Vector){

    this->m_Values = _Vector;
};


float CVector::Get(int _Index) const{

    return this->m_Values[_Index];

};

float* CVector::Get() const{

    return this->m_Values;

};

CVector* CVector::Add(CVector& _rOther){

    float result[this->s_Dimensions];

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] + _rOther[i]
        
    }

    return new CVector(result);
};

void CVector::AddAndSet(CVector& _rOther){

        CVector* temp = this->Add(_rOther);
        this->m_Values = temp->Get();

};

CVector* CVector::Sub(CVector& _rOther){

    float result[this->s_Dimensions];

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] - _rOther[i]
        
    }

    return new CVector(result);
};

void CVector::SubAndSet(CVector& _rOther){

        CVector* temp = this->Sub(_rOther);
        this->m_Values = temp->Get();
        
};


float CVector::GetLength() const{

    double temp = 0.0f

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        temp =+ pow(this->m_Values[i], 2);

    }

    return sqrt(temp);

};

void CVector()
{
    for (int i = 0; i < this->s_Dimensions; i++) {

        this->m_Values[i] = 0;
        
    }
};

void CVector::CVector(float* _Values)
    : m_Values(_Values)
{};

void CVector(CVector& _Vector)
    : m_Values(_Vector.Get())
{};
