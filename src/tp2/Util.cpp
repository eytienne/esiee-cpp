#ifndef TP2_UTIL
#define TP2_UTIL

#include "./Matrix.hpp"
#include "./Vect.hpp"
using namespace std;

class Util {
  public:
	static Vect prod(const Matrix &a, const Vect &b) {
		return Vect(a.data[0].coords[0] * b.coords[0] +
						a.data[0].coords[1] * b.coords[1] +
						a.data[0].coords[2] * b.coords[2],
					a.data[1].coords[0] * b.coords[0] +
						a.data[1].coords[1] * b.coords[1] +
						a.data[1].coords[2] * b.coords[2],
					a.data[2].coords[0] * b.coords[0] +
						a.data[2].coords[1] * b.coords[1] +
						a.data[2].coords[2] * b.coords[2]);
	};
};

#endif