#include "../src/Distributeur.hpp"
#include <cassert>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
using namespace std;

int main() {
	stringstream ss;
	{
		Distributeur distri;
		cereal::BinaryOutputArchive boarchive(ss);
		boarchive(distri);
	}
	cout << "serialized: '" << ss.str() << "'" << endl;
	{
		cereal::BinaryInputArchive biarchive(ss);
		Distributeur distri(false);
		try {
			cout << "log: " << distri.stock_produits.ieme(0)->acces_nom()
				 << endl;
			assert(false);
		} catch (const index_out_of_bounds_exception &e) { assert(true); }
		biarchive(distri);
		cout << "log: " << distri.stock_produits.ieme(0)->acces_nom() << endl;
		distri.run();
	}
}