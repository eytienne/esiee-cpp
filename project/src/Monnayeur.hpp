#ifndef PROJET_MONNAYEUR
#define PROJET_MONNAYEUR

#include <string>
using namespace std;

class Monnayeur {
  private:
	float prix = 0;
	float somme_totale = 0;
	void log();

  public:
	bool exact() const;
	bool assez() const;
	void memorise_prix(float prix);
	void recevoir(float somme);
	float rendre_monnaie();
	float annulation();
	string to_string() const;
	friend ostream &operator<<(ostream &lhs, const Monnayeur &rhs) {
		return lhs << rhs.to_string();
	}
};

#endif