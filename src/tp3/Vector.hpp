#ifndef TP3_VECTOR
#define TP3_VECTOR

#include <string>
using namespace std;

class Vector {
  private:
	double coords[3] = {0};

  public:
	Vector();
    Vector(double x, double y, double z);
	~Vector();
    string to_string() const;
    double dot(Vector b);
    Vector sum(Vector b);
};

#endif