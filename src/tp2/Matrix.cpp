#include "./Matrix.hpp"
#include <algorithm>
#include <sstream>

Matrix::Matrix(const double data[9]) {
	for (short i = 0; i < 3; i++) {
		copy(data + (i * 3), data + (i * 3) + 3, this->data[i].coords);
	}
}

Matrix::~Matrix() {}

string Matrix::to_string() const {
	stringstream ret;
	ret << "Matrix {\n";
	for (short i = 0; i < 3; i++) {
		ret << "\t" << data[i] << "\n";
	}
	ret << "}";
	return ret.str();
}