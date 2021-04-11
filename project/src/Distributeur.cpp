#include "./Distributeur.hpp"
#include "./Produit.hpp"
#include <iostream>
using namespace std;

#define NBMAXPROD 10
Distributeur::Distributeur(bool init) {
	num_produit = -1;
	if (init) {
		Produit *produit;
		produit = new Produit("Orange", 3.00);
		stock_produits.stocker(produit, 5);
		produit = new Produit("Cafe_sans", 5.00);
		stock_produits.stocker(produit, 4);
		produit = new Produit("Cafe_unpeu", 5.00);
		stock_produits.stocker(produit, 3);
		produit = new Produit("Cafe_beaucoup", 6.00);
		stock_produits.stocker(produit, 2);
	}
}

bool Distributeur::produit_demande() const {
	return num_produit != -1;
}
void Distributeur::delivre_produit() {
	if (!monnayeur.assez()) return;
	int res = stock_produits.retirer(num_produit);
	if (res != Stock::OK) {
		cout << "Erreur lors de la demande (" << res << ")" << endl;
		return;
	}
	float prix = monnayeur.lire_prix();
	monnayeur.recevoir(-prix);
	monnayeur.annulation();
	cout << "Produit délivré: " << stock_produits.ieme(num_produit)->acces_nom()
		 << endl;
	if (stock_produits.est_limite()) {
		cout << " [appelez le remplisseur !] " << endl;
	} else {
		cout << " [remplissage OK] " << endl;
	}
}

void Distributeur::demande_produit(int num) {
	num_produit = num;
	monnayeur.memorise_prix(stock_produits.ieme(num)->acces_prix());
}

void Distributeur::annule_demande() {
	num_produit = -1;
}

void Distributeur::run() {
	char rep1, rep2;
	char rep2_s[2] = {'\0'};
	int pnum;
	int fini = 0;
	while (!fini) {
		cout << monnayeur << endl;
		cout << "[P]roduits, [M]onnayeur, [Q]uitter ? ";
		cin >> rep1;
		switch (rep1) {
		case 'P':
		case 'p':
			cout << "[Q]uitter ou nume'ro du produit ? ";
			cin >> rep2;
			switch (rep2) {
			case 'q':
			case 'Q':
				fini = 1;
				break;
			case '1':
			case '2':
			case '3':
			case '4':
				rep2_s[0] = rep2;
				pnum = atoi(rep2_s);
				demande_produit(pnum - 1);
			}
			break;
		case 'm':
		case 'M':
			cout << "[Q]uitter ou [A]nnulation ou" << endl;
			cout << "[0]: 0F50, [1]: 1F, [2]: 2F, [5]: 5F, [D]: 10F ? ";
			cin >> rep2;
			static float piece;
			piece = 0.00;
			switch (rep2) {
			case 'q':
			case 'Q':
				fini = 1;
				break;
			case 'A':
				monnayeur.annulation();
				break;
			case 'D':
				piece += 5.00;
			case '5':
				piece += 3.00;
			case '2':
				piece += 1.00;
			case '1':
				piece += 0.50;
			case '0':
				piece += 0.50;
				monnayeur.recevoir(piece);
				break;
			default:
				cout << "Q ou A ou 0, 1, 2, 5, D !" << endl;
			}
			break;
		case 'q':
		case 'Q':
			fini = 1;
			break;
		default:
			cout << "P ou M ou Q !" << endl;
		}
	}
}