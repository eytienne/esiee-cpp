#ifndef TP4_POINT
#define TP4_POINT

#include <iostream>
using namespace std;

template <typename T> class Point {
	T x, y;

  public:
	Point(T abs = 0, T ord = 0) {
		x = abs;
		y = ord;
	}
	Point(const Point &point) : Point(point.x, point.y) {}
	void affiche() {
		cout << "Coordonnees : " << x << " " << y << "\n";
	}
};

#endif