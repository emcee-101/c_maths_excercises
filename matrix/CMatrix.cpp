

#include "CMatrix.hpp"

CMatrix::CMatrix() {

	s_Values.fill(0.0f);

	for (int posX = 0; posX < heigthAndWidth; posX++) {
	
		for (int posY = 0; posY < heigthAndWidth; posY++) {

			if (posX == posY) {
				s_Values[posX + posY * heigthAndWidth] = 1.0f;
			}

		};

	};

};


CMatrix::CMatrix(CMatrix& _rOther){

	s_Values = *_rOther.Get();

};


std::array<float, CMatrix::heigthAndWidth * CMatrix::heigthAndWidth> * CMatrix::Get(){

	return& s_Values;

};

float CMatrix::Get(int _posX, int _posY) {

	return s_Values[_posX + _posY * CMatrix::heigthAndWidth];

};

void CMatrix::Set(float _val, int _posX, int _posY) {

	s_Values[_posX + _posY * CMatrix::heigthAndWidth] = _val;

};

void CMatrix::Set(CMatrix& _rOther) {

	s_Values = *_rOther.Get();

};

CMatrix* CMatrix::Add(CMatrix& _rOther) {

	CMatrix* result = new CMatrix();



	for (int posX = 0; posX < heigthAndWidth; posX++) {

		for (int posY = 0; posY < heigthAndWidth; posY++) {

			if (posX == posY) {

				result->Set(s_Values[posX + posY * CMatrix::heigthAndWidth] + _rOther.Get(posX, posY), posX, posY);

			};

		};

	};

	return result;

};

void CMatrix::AddAndSet(CMatrix& _rOther) {

	CMatrix* intermediate = Add(_rOther);

	Set(*intermediate);

};

CMatrix* CMatrix::Mul(CMatrix& _rOther) {

	CMatrix* result = new CMatrix();

	for (int posX = 0; posX < heigthAndWidth; posX++) {

		for (int posY = 0; posY < heigthAndWidth; posY++) {

			float newVal = 0.0f;

			for (int posInRow = 0; posInRow < heigthAndWidth; posInRow ++ ) {
			
				newVal += s_Values[ posX + posInRow * heigthAndWidth] * _rOther.Get(posInRow, posY);

			};

			result->Set(newVal, posX, posY);

		};

	};

	return result;

};

void CMatrix::MulAndSet(CMatrix& _rOther) {

	CMatrix* intermediate = Mul(_rOther);
	Set(*intermediate);

};

CVector* CMatrix::Mul(CVector& _Value) {

	CVector* result = new CVector();

	float newVal = 0.0f;

	for (int posX = 0; posX < heigthAndWidth; posX++) {

		for (int posInRow = 0; posInRow < heigthAndWidth; posInRow++) {

			newVal += s_Values[posX + posInRow * heigthAndWidth] * _Value.Get(posInRow);

		};

		result->Set(posX, newVal);

	};

	return result;

};


