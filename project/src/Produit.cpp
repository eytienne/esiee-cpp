#include "./Produit.hpp"
#include <cstring>
#include <iostream>
using namespace std;

Produit::Produit(const char *nom, float prix) {
	int len = strlen(nom);
	this->nom = new char[len];
	strncpy(this->nom, nom, len);
	this->prix = prix;
}

Produit::~Produit() {
	delete nom;
}

const char *Produit::acces_nom() const {
	return nom;
}

float Produit::acces_prix() const {
	return prix;
}