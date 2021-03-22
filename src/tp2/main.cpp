#include "./Matrix.hpp"
#include "./Person.hpp"
#include "./Vect.hpp"
#include "./Util.cpp"
#include <iostream>
#include <cassert>

void exo1() {
	Person *persons[5];
	persons[0] = new Person;
	Person bb;
	persons[1] = &bb;
	persons[2] = new Person("Camus", "Charles", 50);
	Person dd("Dupont", "Didier", 50);
	persons[3] = &dd;
	persons[4] = new Person(dd);
	for (size_t i = 0; i < 5; i++) {
		cout << *persons[i] << endl;
	}
	delete persons[0];
	delete persons[2];
	delete persons[4];
}

void exo2() {
	Matrix identity2((const double[9]){2, 0, 0, 0, 2, 0, 0, 0, 2});
	Vect test(1, 2, 3);
	Vect res = Util::prod(identity2, test);
	cout << identity2 << " * " << test << " = " << res << endl;
}

int main() {
	exo2();
}