#ifndef PROJET_PRODUIT
#define PROJET_PRODUIT

#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>
#include <memory>
#include <string>
using namespace std;

class Produit {
  private:
	string nom;
	float prix;

  public:
	Produit(const char *nom = "", float prix = 0);
	const char *acces_nom() const;
	float acces_prix() const;

	template <class Archive> void serialize(Archive &archive) {
		archive(nom, prix);
	}
};

#endif