#pragma once
#include <array>
#include "../vector/CVector.hpp"

class CMatrix {

/*

		pos = _posX + (_posY * 4)
		 0 < _posX < 4
		 0 < _posY < 4

	Einheitsmatrix:
	/	1	0	0	0	\
	|	0	1	0	0	|
	|	0	0	1	0	|
	\	0	0	0	1	/

*/

	public:

		static int constexpr heigthAndWidth = 4;
		
		CMatrix();
		CMatrix(CMatrix& _rOther);

		std::array<float, heigthAndWidth* heigthAndWidth>* Get();
		float Get(int _posX, int _posY);

		void Set(float _val, int _posX, int _posY);
		void Set(CMatrix& _rOther);

		CMatrix* Add(CMatrix& _rOther);
		void AddAndSet(CMatrix& _rOther);

		CMatrix* Mul(CMatrix& _rOther);
		void MulAndSet(CMatrix& _rOther);

		CMatrix* Mul(CVector& _Value);

	private:

		std::array<float, heigthAndWidth * heigthAndWidth> s_Values;

};

