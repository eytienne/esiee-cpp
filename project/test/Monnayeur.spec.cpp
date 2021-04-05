#include "../src/Monnayeur.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	Monnayeur m;

    m.memorise_prix(5.00);
	m.recevoir(0.5);
	if (m.annulation() == 0.5) { cout << "annulation OK " << endl; }

	m.memorise_prix(5.0);
	m.recevoir(2.0);
	m.recevoir(2.0);
	cout << "assez : " << m.assez() << endl;

    m.recevoir(2.00);
	cout << "exact: " << m.exact() << ", assez: " << m.assez() << endl;

    if (m.rendre_monnaie() == 1.0) {
		cout << "rendre_monnaie OK" << endl;
	} else {
		cout << "rendre_monnaie ERR ! " << endl;
	}
}