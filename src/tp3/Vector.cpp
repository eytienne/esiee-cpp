#include "./Vector.hpp"
#include <sstream>

Vector::Vector() {}
Vector::Vector(double x, double y, double z) {
	coords[0] = x;
	coords[0] = y;
	coords[0] = z;
}

Vector::~Vector() {}

string Vector::to_string() const {
	stringstream ret;
	ret << "Vect{ x: " << coords[0] << ", y: " << coords[1]
		<< ", z: " << coords[2] << " }";
	return ret.str();
}

double Vector::dot(Vector b) {
	return coords[0] * b.coords[0] + coords[1] * b.coords[1] +
		   coords[2] * b.coords[2];
}

Vector Vector::sum(Vector b) {
	return Vector(coords[0] + b.coords[0], coords[1] + b.coords[1],
				  coords[2] + b.coords[2]);
}
