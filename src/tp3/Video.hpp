#ifndef TP3_VIDEO
#define TP3_VIDEO

#include "./Electronical.hpp"
#include <iostream>
using namespace std;

class Video : public Electronical {
  public:
	void show() {
		cout << "Playing the video..." << endl;
	}
};

#endif