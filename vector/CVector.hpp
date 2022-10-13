#pragma once
#include <array>



class CVector {

public:

    static constexpr int s_Dimensions = 4;

    void Set(int _Index, float _Value);
    void Set(CVector* _Vector);

    float Get(int _Index) const;
    std::array<float, s_Dimensions> Get() const;

    CVector* Add(CVector& _rOther);
    void AddAndSet(CVector& _rOther);

    CVector* Sub(CVector& _rOther);
    void SubAndSet(CVector& _rOther);

    CVector* Mul(float _Value);
    void MulAndSet(float _Value);

    float Dot3(CVector& _rOther);
    CVector* Cross3(CVector& _rOther);
    void Cross3AndSet(CVector& _rOther);

    CVector* GetNormalized();
    void Normalize();

    float GetLength() const;

    CVector();
    CVector(std::array<float, 4>& _Values);
    CVector(CVector& _Vector);

private:

    std::array<float, s_Dimensions> m_Values;

};