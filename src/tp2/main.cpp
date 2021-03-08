#include "./Person.hpp"
#include <iostream>

int main() {
	Person *persons[5];
    persons[0] = new Person;
    Person bb;
    persons[1] = &bb;
    persons[2] = new Person("Camus", "Charles", 50);
    Person dd("Dupont", "Didier", 50);
    persons[3] = &dd;
    persons[4] = new Person(dd);
    for (size_t i = 0; i < 5; i++)
    {
        cout << *persons[i] << endl;
    }
    delete persons[0];
    delete persons[2];
    delete persons[4];
}