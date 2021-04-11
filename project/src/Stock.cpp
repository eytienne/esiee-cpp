#include "./Stock.hpp"
#include <cassert>
#include <cstring>

int Stock::nb_sortes() const {
	return rails.size();
}

void Stock::CHECK_VALID(int num_produit) const {
	// assert(num_produit < nb_sortes());
	auto ptr = &rails[num_produit];
	if (ptr == nullptr) throw index_out_of_bounds_exception();
}

int Stock::nb_unites(int num_produit) const {
	CHECK_VALID(num_produit);
	return quantites[num_produit];
}

const Stock::elem *Stock::ieme(int num_produit) const {
	CHECK_VALID(num_produit);
	return rails[num_produit].get();
}

bool Stock::est_vide(int num_produit) const {
	return nb_unites(num_produit) == 0;
}

bool Stock::est_limite() const {
	for (int i = 0; i < quantites.size(); i++) {
		if (quantites[i] < SEUIL) return true;
	}
	return false;
}

int Stock::stocker(elem *adr_produit, int quantite) {
	int idx = rechercher(adr_produit);
	if (idx == ERR_INCONNU) {
		if (nb_sortes() + 1 > MAX_SORTES) return ERR_PLEIN;
		rails.push_back(unique_ptr<elem>(adr_produit));
		quantites.push_back(0);
		idx = nb_sortes() - 1;
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
	for (int i = 0; i < rails.size(); i++) {
		if (rails[i].get() == adr_produit) return i;
	}
	return ERR_INCONNU;
}
