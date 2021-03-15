#ifndef TP3_AUDIO
#define TP3_AUDIO

#include "./Electronical.hpp"
#include <iostream>
using namespace std;

class Audio : public Electronical {
  public:
	void show() {
		cout << "Listening the audio..." << endl;
	}
};

#endif