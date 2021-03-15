#ifndef TP3_NEWSPAPER
#define TP3_NEWSPAPER

#include "./Physical.hpp"
#include <iostream>
using namespace std;

class NewsPaper : public Physical {
  public:
	void show() {
		cout << "Opening the newspaper..." << endl;
	}
};

#endif