#ifndef PROJET_DISTRIBUTEUR
#define PROJET_DISTRIBUTEUR

#include "./Monnayeur.hpp"
#include "./Stock.hpp"

class Distributeur {
  public:
	int num_produit;
	Stock stock_produits;
	Monnayeur monnayeur;

  public:
	Distributeur(bool init = true);
	~Distributeur(){};
	bool produit_demande() const;
	void delivre_produit();
	void annule_demande();
	void demande_produit(int num);
	void run();

	template <class Archive> void serialize(Archive &archive) {
		archive(num_produit, stock_produits, monnayeur);
	}
};
#endif