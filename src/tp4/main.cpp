#include <cassert>
#include <iostream>
using namespace std;

template <typename T> T square(T value) {
	return value * value;
}

void exo1() {
	int a = 3;
	int as = square(a);
	assert(as == 9);
	cout << as << endl;
	float b = 1.5f;
	float bs = square(b);
	assert(bs == 2.25f);
	cout << bs << endl;
	double c = 1.5;
	double cs = square(c);
	assert(cs == 2.25);
	cout << cs << endl;
}

template <typename T> T mysum(const T values[], size_t __s) {
	T ret = 0;
	for (size_t i = 0; i < __s; i++) {
		ret += values[i];
	}
	return ret;
}

// https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
template <class T, size_t N> constexpr size_t len(T (&)[N]) {
	return N;
}

void exo2() {
	int aa[] = {1, 2, 3, 4};
	int sum = mysum(aa, len(aa));
	assert(sum == 10);
	cout << sum << endl;
}

#include "./PointCol.hpp"

void exo3() {
	PointCol<float, int> pca(1.1f, 2.2f, 3);
	cout << pca << endl;
}

#include "./Circle_Comp.hpp"
#include "./Circle_Inh.hpp"

void exo4() {
	Circle_Inh<int> ci(1, 2, 3);
	Circle_Comp<int> cc(Point<int>(1, 2), 3.f);
}

#include "./Stack.hpp"

void exo5() {
	Stack<int> stack(5);
	for (size_t i = 0; i < 6; i++) {
		stack << (i * 2);
	}
	cout << stack << endl;
	assert(++stack);
	for (size_t i = 0; i < 6; i++) {
		int temp;
		stack >> temp;
		cout << "pop: " << temp << endl;
	}
	cout << stack << endl;
	assert(--stack);
}

void all_exos() {
	exo1();
	exo2();
	exo3();
	exo4();
	exo5();
}

int main(int argc, char const *argv[]) {
	all_exos();
	return 0;
}
