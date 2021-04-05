#include "../src/Stock.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int err;
	Produit *p;
	Stock stock;

	cout << "nb sortes = " << stock.nb_sortes() << endl;

	p = new Produit("U");
	if ((err = stock.stocker(p, 4)) != 0) {
		cout << "stocker ERR = " << err << endl;
	}
	cout << "sortes, unites(0), plein(0) = " << stock.nb_sortes() << ", "
		 << stock.nb_unites(0) << ", " << stock.est_plein(0) << endl;

	p = new Produit("D");
	if ((err = stock.stocker(p, 10)) != 0) {
		cout << "stocker ERR = " << err << endl;
	}
	cout << "sortes, unites(1), plein(1) = " << stock.nb_sortes() << ", "
		 << stock.nb_unites(1) << ", " << stock.est_plein(1) << endl;

	if (p == stock.ieme(1)) {
		cout << "ieme OK" << endl;
	} else {
		cout << "ieme ERR !" << endl;
	}

	cout << "vide(0, 1), limite = " << stock.est_vide(0) << ", "
		 << stock.est_vide(1) << ", " << stock.est_limite() << endl;
	for (int i = 0; i < 4 + 1; i++) {
		if ((err = stock.retirer(0)) != 0) {
			cout << "retirer ERR = " << err << endl;
		}
	}
	cout << "vide(0, 1), limite = " << stock.est_vide(0) << ", "
		 << stock.est_vide(1) << ", " << stock.est_limite() << endl;

	return 0;
}