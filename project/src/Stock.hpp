#ifndef PROJET_STOCK
#define PROJET_STOCK

#include "./Produit.hpp"
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>
using namespace std;

class index_out_of_bounds_exception : public exception {
  public:
	virtual const char *what() const throw() {
		return "Index out of bounds!";
	}
};
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
	vector<int> quantites{};
	vector<unique_ptr<elem>> rails{};
	void CHECK_VALID(int num_produit) const;
	int traite_vide(int);

  public:
	int nb_sortes() const;
	int nb_unites(int num_produit) const;
	const elem *ieme(int num_produit) const;
	bool est_vide(int num_produit) const;
	bool est_limite() const;
	int stocker(elem *adr_produit, int quantite);
	int retirer(int);
	bool est_plein(int num_produit) const;
	int rechercher(const elem *adr_produit) const;

	template <class Archive> void serialize(Archive &archive) {
		archive(CEREAL_NVP(quantites), CEREAL_NVP(rails));
	}
};

#endif