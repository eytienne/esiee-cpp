#ifndef TP2_VECT
#define TP2_VECT

#include <string>
using namespace std;

class Vect {
	friend class Matrix;
	friend class Util;

  private:
	double coords[3];

  public:
	Vect(double x = 0., double y = 0., double z = 0.);
	~Vect();
	string to_string() const;
	friend ostream &operator<<(ostream &ss, const Vect &pp) {
		return ss << pp.to_string();
	};
};

#endif