#include <cassert>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <new>
#include <regex>
#include <cstdlib>
#include <string>
#include <sys/resource.h>
#include <type_traits>
using namespace std;

void affecte(float *e, int divider) {
	cerr << divider << endl;
	*e = divider ? 1.0f / divider : divider;
}

void exo1() {
	float *e = new float;
	string buffer;
	srand(time(NULL));
	while (true) {
		cout << "Continue ? (y/N) ";
		getline(cin, buffer);
		if (buffer == "y") {
			affecte(e, rand() % 11);
			if (*e) {
				cout << *e;
			} else {
				cout << "Infinity";
			}
			cout << endl;
		} else if (regex_match(buffer, regex("n?", regex_constants::icase))) {
			break;
		} else {
			cout << "Bad choice" << endl;
		}
	}
}

class Date {
  public:
	int year;
	int month;
	int day;

	Date(int year = 1970, int month = 1, int day = 1) {
		this->year = year;
		this->month = month;
		this->day = day;
	}

	int *get_field(string query) {
		return query == "year"
				   ? &this->year
				   : query == "month" ? &this->year
									  : query == "day" ? &this->day : NULL;
	}

	string to_string() const {
		const int ret_size = 11;
		char ret[ret_size];
		snprintf(ret, ret_size, "%4d/%02d/%02d", this->year, this->month,
				 this->day);
		return string(ret);
	}

	friend ostream &operator<<(ostream &ss, const Date &dd) {
		return ss << dd.to_string();
	}
};

void exo2() {
	Date dd;
	string query;
	string buffer;
	cout << "Date:" << dd << endl;
	while (true) {
		cout << "Edit ? (year|month|day|SKIP) ";
		getline(cin, query);
		if (regex_match(query, regex("(year|month|day)"))) {
			cout << "Enter: ";
			getline(cin, buffer);
			uint value = stoi(buffer);
			if (query == "year") {
				if (value >= 10000) {
					cerr << "Year not supported" << endl;
					exit(EXIT_FAILURE);
				}
			} else {
				if (query == "month") {
					if (value >= 12) {
						cerr << "Month not supported" << endl;
						exit(EXIT_FAILURE);
					}
				} else {
					if (value >= 31) {
						cerr << "Day not supported" << endl;
						exit(EXIT_FAILURE);
					}
				}
			}
			*dd.get_field(query) = value;
		} else if (regex_match(query,
							   regex("(skip)?", regex_constants::icase))) {
			goto end;
		} else {
			cout << "Bad choice: " << query << endl;
		}
	}
end:
	cout << "Result:" << dd << endl;
}

/**
 * @pre n > 0
 */
double sum_pows(float c, uint n = 2) {
	assert(n > 0);
	double ret;
	for (uint i = 1; i <= n; i++) {
		ret += powf(c, i);
	}
	return ret;
}

void exo3() {
	string buffer;
	cout << "Enter c:";
	getline(cin, buffer);
	int cc = stoi(buffer);
	cout << "Enter n:";
	getline(cin, buffer);
	int nn = stoi(buffer);
	cout << "Result: " << sum_pows(cc, nn) << endl;
}

template <typename T> T my_prompt() {
	T data;
	if (is_same<T, int>::value) {
		cout << "Integer ? ";
	} else if (is_same<T, float>::value) {
		cout << "Real ? ";
	} else if (is_same<T, char>::value) {
		cout << "Char ? ";
	} else {
		return NULL;
	}
	cin >> data;
	return data;
}

void exo4() {
	int idata = my_prompt<int>();
	cout << "Entered: " << idata << endl;
	float fdata = my_prompt<float>();
	cout << "Entered: " << fdata << endl;
	char cdata = my_prompt<char>();
	cout << "Entered: " << cdata << endl;
}

void aie() {
	cout << "No more memory\n";
	cout << "Shutting down\n";
	exit(EXIT_FAILURE);
}

#define MB(x)	((size_t) (x) << 20)
void exo5() {
	struct rlimit new_limit = {
		.rlim_max = MB(4000),
	};
	// avoids freezing
	setrlimit(RLIMIT_DATA, &new_limit);
	set_new_handler(aie);
	int block_size = 1;
	cout << "Block size ? ";
	cin >> block_size;
	while (true) {
		char *buffer = new char[block_size];
		delete buffer;
	}
}

int main() {
	exo5();
}
