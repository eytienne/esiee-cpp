#include "./IntStack.hpp"
#include "./assert.h"

IntStack::IntStack(int n) {
	data = new vector<int>(n, 0);
}

IntStack::IntStack(const IntStack &is) {
	data = new vector<int>(*is.data);
}

IntStack::~IntStack() {
	delete data;
}

void IntStack::push(int v) {
	data->push_back(v);
}

int IntStack::pop() {
	assert(!empty());
	int ret = data->back();
	data->pop_back();
	return ret;
}

bool IntStack::full() {
	return data->size() == data->capacity();
}

bool IntStack::empty() {
	return data->size() == 0;
}

void operator<(IntStack &lhs, const int &rhs) {
	lhs.push(rhs);
}

void operator>(IntStack &lhs, int &rhs) {
	rhs = lhs.pop();
}