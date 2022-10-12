#pragma once

class CVector{

    public:
        
        static constexpr int s_Dimensions = 4;

        void Set(int _Index, float _Value);
        void Set(CVector& _Vector);

        float Get(int _Index) const;
        float Get() const;

        CVector* Add(CVector& _rOther);
        void AddAndSet(CVector& _rOther);

        CVector* Sub(CVector& _rOther);
        void SubAndSet(CVector& _rOther);

        float GetLength() const;
        CVector* GetCross(const CVector& _rOther) const;

        void CVector();
        void CVector(float* _Values);
        void CVector(CVector* _Vector);

    private:

        float m_Values[s_Dimensions];

}