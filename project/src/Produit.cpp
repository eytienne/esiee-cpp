#include "./Produit.hpp"
#include <cstring>
#include <iostream>

Produit::Produit(const char *nom, float prix) {
	int len = strlen(nom);
	this->nom = string(nom);
	this->prix = prix;
}

const char *Produit::acces_nom() const {
	return nom.c_str();
}

float Produit::acces_prix() const {
	return prix;
}