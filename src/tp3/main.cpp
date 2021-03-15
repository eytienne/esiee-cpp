#include "./IntStack.hpp"
#include <iostream>
using namespace std;

void part1() {
	int i;
	IntStack a(3), b;
	cout << "a full ? " << a.full() << "\n";
	cout << "a empty ? " << a.empty() << "\n";
	a.push(3);
	a.push(9);
	a.push(11);
	cout << "Contenu de a : ";
	for (i = 0; i < 3; i++) {
		cout << a.pop() << " ";
	}
	cout << "\n";
	for (i = 0; i < 30; i++) {
		b.push(10 * i);
	}
	cout << "Contenu de b : ";
	for (i = 0; i < 30; i++) {
		if (!b.empty()) { cout << b.pop() << " "; }
	}
	cout << "\n";
	IntStack *adp = new IntStack(5);
	cout << "pile dynamique empty ? " << adp->empty() << "\n";
	for (i = 0; i < 10; i++) {
		adp->push(10 * i);
	}
	cout << "Contenu de la pile dynamique : ";
	for (i = 0; i < 10; i++) {
		if (!adp->empty()) { cout << adp->pop() << " "; }
	}
	IntStack c(3); // une pile a de 3 entiers
	c.push(5);
	c.push(12);
	IntStack d = c; // une pile b égale à a
	cout << "Contenu de d : ";
	for (i = 0; i < 3; i++) {
		if (!d.empty()) { cout << d.pop() << " "; }
	}
	cout << "\n";
}

void part2_1() {
	IntStack is(3);
	cout << "is full ? " << is.full() << "\n";
	cout << "is empty ? " << is.empty() << "\n";
	is < 3;
	is < 9;
	is < 11;
	cout << "Contenu de a : ";
	for (int i = 0; i < 3; i++) {
		int temp;
		is > temp;
		cout << temp << " ";
	}
	cout << endl;
}

#include "./mystring.hpp"

void part2_2() {
	mystring a;
	mystring b("bonjour");
	mystring c = b;
	cout << "a : " << a << "\n";
	cout << "b : " << b << "\n";
	cout << "c : " << c << "\n";

	mystring d("hello");
	a = b = d;
	cout << "b : " << b << "\n";
	cout << "a : " << a << "\n";
	cout << "a == b : " << (a == b) << "\n";

	mystring x("salut "), y("chère "), z("madame");
	a = x + y + z;
	cout << "a : " << a << "\n";
	a = a;
	cout << "a : " << a << "\n";
	mystring e("xxxxxxxxxx");
	for (char cr = 'a', i = 0; cr < 'f'; cr++, i++)
		e[i] = cr;
	cout << "e : " << e << "\n";
}

#include "./Audio.hpp"
#include "./Book.hpp"
#include "./Medium.hpp"
#include "./MultiMedia.hpp"
#include "./NewsPaper.hpp"
#include "./Video.hpp"

void part3_1() {
	Medium *media[4];
	media[0] = new Audio;
	media[1] = new Book;
	media[2] = new NewsPaper;
	media[3] = new Video;
	for (size_t i = 0; i < 4; i++) {
		media[i]->show();
		delete media[i];
	}

	MultiMedia mm;
	mm.show();
}

#include "./mystring_t.hpp"
#include "./assert.h"

void part3_2() {
	mystring_t mst;

	mst = "123";
	mst.compute();
	cout << mst << endl;
	assert(mst.type);

	mst = "+0.0E123";
	mst.compute();
	cout << mst << endl;
	assert(mst.type);

	mst = "NOPE";
	mst.compute();
	cout << mst << endl;
	assert(!mst.type);
}

int main() {
	part3_2();
}