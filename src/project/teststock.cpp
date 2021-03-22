#include "stock.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]) {
	int err;
	char *p;

	init_stock();
	cout << "nb sortes = " << nb_sortes() << endl;

	p = new char('U');
	if ((err = stocker(p, 4)) != 0)
		cout << "stocker ERR = " << err << endl;
	cout << "sortes, unites(0), plein(0) = " << nb_sortes() << ", "
		 << nb_unites(0) << ", " << est_plein(0) << endl;

	p = new char('D');
	if ((err = stocker(p, 10)) != 0)
		cout << "stocker ERR = " << err << endl;
	cout << "sortes, unites(1), plein(1) = " << nb_sortes() << ", "
		 << nb_unites(1) << ", " << est_plein(1) << endl;

	if (p == ieme(1))
		cout << "ieme OK" << endl;
	else
		cout << "ieme ERR !" << endl;

	cout << "vide(0, 1), limite = " << est_vide(0) << ", " << est_vide(1)
		 << ", " << est_limite() << endl;
	for (int i = 0; i < 4 + 1; i++)
		if ((err = retirer(0)) != 0)
			cout << "retirer ERR = " << err << endl;
	cout << "vide(0, 1), limite = " << est_vide(0) << ", " << est_vide(1)
		 << ", " << est_limite() << endl;

	return 0;
}