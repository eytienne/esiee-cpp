#include "./Vect.hpp"
#include <sstream>

Vect::Vect(double x, double y, double z) {
	this->coords[0] = x;
	this->coords[1] = y;
	this->coords[2] = z;
}

Vect::~Vect() {}

string Vect::to_string() const {
	stringstream ret;
	ret << "Vect{ x: " << this->coords[0] << ", y: " << this->coords[1] << ", z: " << this->coords[2] << " }";
	return ret.str();
}
