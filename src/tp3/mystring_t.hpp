#ifndef TP3_MYSTRING_T
#define TP3_MYSTRING_T

#include "./mystring.hpp"

class mystring_t : public mystring {
  public:
	bool type;
	float val;

	mystring_t();
	template <typename T> mystring_t(const T init);
	mystring_t(const mystring_t &mst);
	string to_string() const;
	void compute();
};

#endif