#ifndef PROJET_DISTRIBUTEUR
#define PROJET_DISTRIBUTEUR

#include "./Monnayeur.hpp"
#include "./Stock.hpp"

class Distributeur {
  private:
	int num_produit;
	Stock stock_produits;
	Monnayeur monnayeur;

  public:
	Distributeur();
	~Distributeur(){};
	bool produit_demande() const;
	void delivre_produit();
	void annule_demande();
	void demande_produit(int num);
	void run();
};
#endif