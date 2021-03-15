#ifndef TP3_BOOK
#define TP3_BOOK

#include "./Physical.hpp"
#include <iostream>
using namespace std;

class Book : public Physical {
  public:
	void show() {
		cout << "Reading the book..." << endl;
	}
};

#endif