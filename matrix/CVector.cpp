#include "CVector.hpp"
#include <cmath>

void CVector::Set(int _Index, float _Value){

    this->m_Values.at(_Index) = _Value;

};

void CVector::Set(CVector* _Vector){

    this->m_Values = _Vector->Get();
};


float CVector::Get(int _Index) const{

    return this->m_Values[_Index];

};

std::array<float, CVector::s_Dimensions> CVector::Get() const{

    return m_Values;

};

CVector* CVector::Add(CVector& _rOther){

    std::array<float, s_Dimensions> result = {};

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] + _rOther.Get(i);
        
    }

    return new CVector(result);
};

void CVector::AddAndSet(CVector& _rOther){

        this->Set(this->Add(_rOther));

};

CVector* CVector::Sub(CVector& _rOther){

    std::array<float, s_Dimensions> result = {};

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] - _rOther.Get(i);
        
    }

    return new CVector(result);
};

void CVector::SubAndSet(CVector& _rOther){

        this->Set(this->Sub(_rOther));
        
};

CVector* CVector::Mul(float _Value){

    std::array<float, s_Dimensions> result = {};

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        result[i] = this->m_Values[i] * _Value;
        
    }

    return new CVector(result);
};

void CVector::MulAndSet(float _Value){

    this->Set(this->Mul(_Value));
        
};

float CVector::Dot3(CVector& _rOther){

    float result = 0.0f;

    for (int i = 0; i < 3; i++) {
        
        result += this->m_Values[i] * (_rOther.Get(i));
        
    }

    return result;
    
};

CVector* CVector::Cross3(CVector& _rOther){
    
    std::array<float, CVector::s_Dimensions> result;

    result[0] = this->m_Values[1] * _rOther.Get()[2] - this->m_Values[2] * _rOther.Get()[1];
    result[1] = this->m_Values[2] * _rOther.Get()[0] - this->m_Values[0] * _rOther.Get()[2];
    result[2] = this->m_Values[0] * _rOther.Get()[1] - this->m_Values[1] * _rOther.Get()[0];
    result[3] = this->m_Values[3];

    return new CVector(result);

};

void CVector::Cross3AndSet(CVector& _rOther){

    this->Set(this->Cross3(_rOther));
        
};



float CVector::GetLength() const{

    double temp = 0.0f;

    for (int i = 0; i < this->s_Dimensions; i++) {
        
        temp += pow(this->m_Values[i], 2);

    }

    return sqrt(temp);

};

CVector* CVector::GetNormalized(){

    return this->Mul( 1 /  ( this->GetLength() ));

};

void CVector::Normalize(){

    this->Set(this->GetNormalized());

};

CVector::CVector()
{

    m_Values.fill(0);

};

CVector::CVector(std::array<float, CVector::s_Dimensions>& _Values)
    : m_Values(_Values)
{};

CVector::CVector(CVector& _Vector)
    : m_Values(_Vector.Get())
{};
