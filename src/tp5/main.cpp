#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

const char *float_format(int precision, bool exponential = false) {
	stringstream ss;
	ss << "%." << precision << (exponential ? "e" : "f");
	return ss.str().c_str();
}

void exo1() {
	float aa;
	cin >> aa;
	for (int i = 0; i < 11; i++) {
		cout << setprecision(i) << fixed << aa << endl;
		cout << setprecision(i) << scientific << aa << endl;
	}
}

#include <fstream>

void exo2(int argc, char const *argv[]) {
	if (argc != 2) {
		perror("Call with file as argument\n");
		exit(EXIT_FAILURE);
	}
	const char *filename = argv[1];

	ofstream output(filename, ios::out | ios::binary);
	if (!output) {
		cerr << "Cannot open file: " << filename << endl;
		exit(EXIT_FAILURE);
	}

	int cur;
	while (1) {
		cin >> cur;
		if (cur == 0) break;
		output << cur << endl;
	}
	output.close();
}

void exo3(int argc, char const *argv[]) {
	if (argc != 2) {
		perror("Call with file as argument\n");
		exit(EXIT_FAILURE);
	}
	const char *filename = argv[1];

	ifstream input(filename, ios::in | ios::binary);
	if (!input) {
		cerr << "Cannot open file: " << filename << endl;
		exit(EXIT_FAILURE);
	}

	int cur;
	while (input >> cur) {
		cout << cur << endl;
	}
	input.close();
}

#include <vector>

void exo4(int argc, char const *argv[]) {
	if (argc != 2) {
		perror("Call with file as argument\n");
		exit(EXIT_FAILURE);
	}
	const char *filename = argv[1];

	ifstream input(filename, ios::in | ios::binary);
	if (!input) {
		cerr << "Cannot open file: " << filename << endl;
		exit(EXIT_FAILURE);
	}

	int cur;
	vector<int> values;
	while (input >> cur) {
		values.push_back(cur);
	}
	input.close();

	int cmd;
	while (1) {
		cout << "Request? ";
		cin >> cmd;
		if (cmd == 0) break;
		if (cmd <= values.size()) {
			cout << "Result: " << values[cmd - 1] << endl;
		} else {
			cout << "Bad index" << endl;
		}
	}
}

#include <string>

void exo5(int argc, char const *argv[]) {
	if (argc != 3) {
		perror("Call with args: <src> <dest>\n");
		exit(EXIT_FAILURE);
	}
	const char *src = argv[1], *dest = argv[2];

	ifstream input(src, ios::in | ios::binary);
	if (!input) {
		cerr << "Cannot open file: " << src << endl;
		exit(EXIT_FAILURE);
	}
	ofstream output(dest, ios::out | ios::binary);
	if (!output) {
		cerr << "Cannot write file: " << dest << endl;
		exit(EXIT_FAILURE);
	}

	char buffer[BUFSIZ];
	while (!input.eof()) {
		input.read(buffer, BUFSIZ);
		output << buffer;
	}
	input.close();
	output.close();
}

void exo6(int argc, char const *argv[]) {
	if (argc < 2) {
		perror("No file given\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++) {
		const char *filename = argv[i];
		ifstream input(filename, ios::in | ios::binary);
		if (!input) {
			cerr << "cat: " << filename << ": No such file or directory"
				 << endl;
			continue;
		}
		stringstream output;
		char buffer[BUFSIZ];
		while (!input.eof()) {
			input.read(buffer, BUFSIZ);
			output << buffer;
		}
		input.close();
		cout << output.str();
	}
}

#include <list>

void exo7() {
	list<char> buf;
	string cur;
	while (1) {
		cin >> cur;
		if (cur[0] == '#') break;
		buf.push_back(cur[0]);
	}
	buf.push_back('\0');

	cout << "Input:";
	list<char>::iterator p = buf.begin();
	while (p != buf.end()) {
		cout << " " << *p;
		p++;
	}
	cout << endl;
	buf.sort();
	cout << "Sorted:";
	p = buf.begin();
	while (p != buf.end()) {
		cout << " " << *p;
		p++;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	exo7();
}
