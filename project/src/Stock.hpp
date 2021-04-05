#ifndef PROJET_STOCK
#define PROJET_STOCK

#include "./Produit.hpp"

class Stock {
  public:
	typedef Produit elem;
	static const int MAX_SORTES = 5;
	static const int MAX_QUANTITE = 10;
	static const int ERR_INCONNU = -1;
	static const int ERR_INTERVALLE = 0;
	static const int OK = 0;
	static const int ERR_PLEIN = 1;
	static const int ERR_VIDE = 2;
	static const int ERR_DEP = 3;
	static const int SEUIL = 2;

  private:
	int index = 0;
	int quantites[MAX_SORTES] = {0};
	elem *rails[MAX_SORTES] = {nullptr};
	void CHECK_VALID(int num_produit) const;
	int traite_vide(int);

  public:
	int nb_sortes() const;
	int nb_unites(int num_produit) const;
	elem *ieme(int num_produit) const;
	bool est_vide(int num_produit) const;
	bool est_limite() const;
	int stocker(elem *adr_produit, int quantite);
	int retirer(int);
	bool est_plein(int num_produit) const;
	int rechercher(const elem *adr_produit) const;
};

#endif