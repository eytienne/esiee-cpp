#include "./Monnayeur.hpp"
#include <cmath>
#include <iostream>
#include <sstream>

bool Monnayeur::exact() const {
	return somme_totale == prix;
}

bool Monnayeur::assez() const {
	return somme_totale >= prix;
}

void Monnayeur::log() {
	cout << "somme rendue = " << fmax(0, somme_totale - prix)
		 << ", à payer = " << fmax(0, prix - somme_totale) << endl;
}

float Monnayeur::lire_prix() const {
	return prix;
}

void Monnayeur::memorise_prix(float prix) {
	this->prix = prix;
	log();
}

void Monnayeur::recevoir(float somme) {
	somme_totale += somme;
	cout << "somme_totale = " << somme_totale << endl;
}

float Monnayeur::rendre_monnaie() {
	float ret = somme_totale;
	somme_totale = 0;
	cout << "somme rendue = " << ret << endl;
	log();
	return ret;
}

float Monnayeur::annulation() {
	prix = 0;
	return rendre_monnaie();
}

string Monnayeur::to_string() const {
	stringstream ret;
	ret << "Monnayeur { prix: " << prix << ", somme_totale: " << somme_totale
		<< " }";
	return ret.str();
}