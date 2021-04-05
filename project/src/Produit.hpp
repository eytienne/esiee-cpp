#ifndef PROJET_PRODUIT
#define PROJET_PRODUIT

class Produit {
  private:
	char *nom;
	float prix;

  public:
	Produit(const char *nom, float prix = 0);
	~Produit();
	const char *acces_nom() const;
	float acces_prix() const;
};

#endif