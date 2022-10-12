#include "CVector.hpp"
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
        
        result[i] = this->m_Values[i] + _rOther[i];
        
    }

    return new CVector(result);
};

void CVector::AddAndSet(CVector& _rOther){

        this->Set(this->Add(_rOther));

};

CVector* CVector::Sub(CVector& _rOther){

    float result[this->s_Dimensions];

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] - _rOther[i];
        
    }

    return new CVector(result);
};

void CVector::SubAndSet(CVector& _rOther){

        this->Set(this->Sub(_rOther));
        
};

CVector* CVector::Mul(float _Value){

    float result[this->s_Dimensions];

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] * _Value;
        
    }

    return new CVector(result);
};

void CVector::MulAndSet(float _Value){

    this->Set(this->Mul(_rOther));
        
};

float CVector::Dot3(CVector& _rOther){

    float result;

    for (int i = 0; i < 3; i++) {
        
        result =+ this->m_Values[i] * _rOther->Get()[i];
        
    }

    return result;
    
};

CVector* CVector::Cross3(CVector& _rOther){

    float result[3];

    result[0] = this->m_Values[1] * _rOther->Get()[2] - this->m_Values[2] * _rOther->Get()[1];
    result[1] = this->m_Values[2] * _rOther->Get()[0] - this->m_Values[0] * _rOther->Get()[2];
    result[2] = this->m_Values[0] * _rOther->Get()[1] - this->m_Values[1] * _rOther->Get()[0];

    return new CVector(result);

};

void CVector::Cross3AndSet(CVector& _rOther){

    this->Set(this->Cross3(_rOther));
        
};



float CVector::GetLength() const{

    double temp = 0.0f

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        temp =+ pow(this->m_Values[i], 2);

    }

    return sqrt(temp);

};

CVector* CVector::GetNormalized(){

    return this->Mul( 1 /  ( this->GetLength() ));

};

void CVector::Normalize(){

    this->Set(this->GetNormalized());

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
