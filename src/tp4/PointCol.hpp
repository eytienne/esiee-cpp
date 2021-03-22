#ifndef TP4_POINTCOL
#define TP4_POINTCOL

#include <sstream>
#include <string>
using namespace std;

template <typename T_Coords, typename T_Color> class PointCol {
  private:
	T_Coords coords1, coords2;
	T_Color color;

  public:
	PointCol(T_Coords coords1, T_Coords coords2, T_Color color) {
		this->coords1 = coords1;
		this->coords2 = coords2;
		this->color = color;
	}
	~PointCol() {}
	string to_string() const {
		stringstream ret;
		ret << "PointCol{ coords1: " << coords1 << ", coords2: " << coords2
			<< ", color: " << color << " }";
		return ret.str();
	}
	friend ostream &operator<<(ostream &lhs, const PointCol &rhs) {
		return lhs << rhs.to_string();
	}
};

#endif