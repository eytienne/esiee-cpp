#include "../src/Produit.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	Produit p1("un", 11), p2("deux", 22);
	cout << "p1: " << p1.acces_nom() << ", " << p1.acces_prix() << endl;
	cout << "p2: " << p2.acces_nom() << ", " << p2.acces_prix() << endl;
	return 0;
}