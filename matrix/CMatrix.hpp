#pragma once
#include <array>
#include "CVector.hpp"


class CMatrix {

/*
*
*		pos = _posX + (_posY * 4)
*		 0 < _posX < 4
*		 0 < _posY < 4
*
*	Einheitsmatrix:
*	/	1	0	0	0	\
*	|	0	1	0	0	|
*	|	0	0	1	0	|
*	\	0	0	0	1	/
*
*	THIS IS COLLUMN MAJOR ORDER
*
*/

	public:

		static int constexpr heigthAndWidth = 4;
		
		CMatrix();
		CMatrix(CMatrix& _rOther);

		// missing const after function

		std::array<float, heigthAndWidth* heigthAndWidth>* Get();
		float Get(int _posX, int _posY);

		void Set(float _val, int _posX, int _posY);
		void Set(CMatrix& _rOther);

		// return by value and not by reference because new is used here and needs to be deleted. 
		// that is something that WILL be overlooked tough (COULD BE DONE WITH DOCU, BUT WOULD BE TERRIBLE DESIGN FOR A LIBRARY)

		// can also work with overloading the "+"-operator

		CMatrix* Add(CMatrix& _rOther);
		void AddAndSet(CMatrix& _rOther);

		CMatrix* Mul(CMatrix& _rOther);
		void MulAndSet(CMatrix& _rOther);

		// usage of collumn or row vector relevant for efficiency, 
		// if the opportunity is used to implement s_Values suing using an array of vectors, 
		// because of the way multiplication between matrix and vector works
		
		CVector* Mul(CVector& _Value);

	private:

		// can also be realised by using an array of 4 vectors ... pro more efficient in writing the code

		std::array<float, heigthAndWidth * heigthAndWidth> s_Values;

};

