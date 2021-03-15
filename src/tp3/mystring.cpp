#include "./mystring.hpp"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>

mystring::mystring(int len, const char *data) {
	this->len = len;
	this->data = new char[len];
	strncpy(this->data, data, len);
}

mystring::mystring(const char *init) : mystring((int)strlen(init), init) {}

mystring::mystring(const mystring &ms) : mystring(ms.len, ms.data) {}

mystring::~mystring() {}

string mystring::to_string() const {
	stringstream ret;
	char buf[len + 1];
	snprintf(buf, len + 1, "%s", data);
	buf[len] = '\0';
	ret << buf;
	return ret.str();
}

void mystring::swap(mystring &rhs) {
	std::swap(len, rhs.len);
	std::swap(data, rhs.data);
}

template <typename T> mystring &mystring::operator=(const T &rhs) {
	mystring ret(rhs);
	swap(ret);
	return *this;
}

bool mystring::operator==(const mystring &rhs) const {
	if (this == &rhs) return true;
	if (len != rhs.len) return false;
	return strncmp(data, rhs.data, len) == 0;
}

mystring mystring::operator+(const mystring &rhs) const {
	mystring ret;
	ret = *this;
	strncmp(ret.data + len, rhs.data, rhs.len);
	ret.len += rhs.len;
	return ret;
}

const char &mystring::operator[](int idx) const {
	return data[idx];
}

char &mystring::operator[](int idx) {
	return data[idx];
}