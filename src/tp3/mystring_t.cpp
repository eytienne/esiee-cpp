#include "./mystring_t.hpp"
#include <cstdlib>
#include <regex>
#include <sstream>

mystring_t::mystring_t() : mystring_t("") {}

template <typename T> mystring_t::mystring_t(const T init) : mystring(init) {
	type = false;
	val = 0;
};

string mystring_t::to_string() const {
	stringstream ret;
	ret << mystring::to_string() << " (type: " << type << ", val: " << val
		<< ")";
	return ret.str();
}

void mystring_t::compute() {
	val = atof(data);
	type = val != 0 || regex_match(data, regex("[+-]?(0+(\\.0*)?|\\.0+)(e\\d+)?", regex_constants::icase));
}
