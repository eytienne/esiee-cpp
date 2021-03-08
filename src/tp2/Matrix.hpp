#ifndef TP2_MATRIX
#define TP2_MATRIX

#include "./Vect.hpp"

class Matrix {
	friend class Vect;
	friend class Util;

  private:
	Vect data[3];

  public:
	Matrix(const double data[9] = { 0 });
	~Matrix();
	string to_string() const;
	friend ostream &operator<<(ostream &ss, const Matrix &pp) {
		return ss << pp.to_string();
	};
};

#endif
