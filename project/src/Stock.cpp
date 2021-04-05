#include "./Stock.hpp"
#include <cassert>
#include <cstring>

int Stock::nb_sortes() const {
	return index;
}

void Stock::CHECK_VALID(int num_produit) const{
	assert(num_produit < MAX_SORTES);
}

int Stock::nb_unites(int num_produit) const {
	CHECK_VALID(num_produit);
	return quantites[num_produit];
}

Stock::elem *Stock::ieme(int num_produit) const {
	CHECK_VALID(num_produit);
	return rails[num_produit];
}

bool Stock::est_vide(int num_produit) const {
	return nb_unites(num_produit) == 0;
}

bool Stock::est_limite() const {
	for (int i = 0; i < MAX_SORTES; i++) {
		if (quantites[i] < SEUIL) return true;
	}
	return false;
}

int Stock::stocker(elem *adr_produit, int quantite) {
	int idx = rechercher(adr_produit);
	if (idx == ERR_INCONNU) {
		if (index + 1 > MAX_SORTES) return ERR_PLEIN;
		rails[index] = adr_produit;
		idx = index;
		index++;

	} else {
		if (est_plein(idx)) return ERR_PLEIN;
		if (quantites[idx] + quantite > MAX_QUANTITE) return ERR_DEP;
	}
	quantites[idx] += quantite;
	return OK;
}

int Stock::retirer(int num_produit) {
	CHECK_VALID(num_produit);
	if (est_vide(num_produit)) return traite_vide(num_produit);
	quantites[num_produit]--;
	return OK;
}

int Stock::traite_vide(int num_produit) {
	return ERR_VIDE;
}

bool Stock::est_plein(int num_produit) const {
	return nb_unites(num_produit) >= MAX_QUANTITE;
}

int Stock::rechercher(const elem *adr_produit) const {
	for (int i = 0; i < MAX_SORTES; i++) {
		if (rails[i] == adr_produit) return i;
	}
	return ERR_INCONNU;
}
