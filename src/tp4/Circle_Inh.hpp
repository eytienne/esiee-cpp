#ifndef TP4_CIRCLE_INH
#define TP4_CIRCLE_INH

#include "./Point.hpp"

template <typename T_Point> class Circle_Inh : Point<T_Point> {
  private:
	float radius;

  public:
	Circle_Inh(T_Point abs, T_Point ord, float radius)
		: Point<T_Point>(abs, ord) {
		this->radius = radius;
	}
};

#endif