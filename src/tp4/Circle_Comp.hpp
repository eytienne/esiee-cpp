#ifndef TP4_CIRCLE_COMP
#define TP4_CIRCLE_COMP

#include "./Point.hpp"

template <typename T_Point> class Circle_Comp {
  private:
	Point<T_Point> point;
	float radius;

  public:
	Circle_Comp(Point<T_Point> point, float radius) {
		this->point = point;
		this->radius = radius;
	}
};

#endif