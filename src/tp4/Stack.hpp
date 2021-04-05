#ifndef TP4_STACK
#define TP4_STACK

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Stack {
  private:
	vector<T> *data;
	int capacity;

  public:
	Stack(int n = 20) {
		data = new vector<T>();
		capacity = n;
	}
	Stack(const Stack &is) {
		data = new vector<int>(*is.data);
		capacity = is.capacity;
	}
	~Stack() {
		delete data;
	}
	void push(T v) {
		if (full()) { return; }
		data->push_back(v);
	}
	T pop() {
		if (empty()) return (T)nullptr;
		T ret = data->back();
		data->pop_back();
		return ret;
	}
	bool full() {
		return data->size() == capacity;
	}
	bool empty() {
		return data->empty();
	}
	friend void operator<<(Stack &lhs, const T &rhs) {
		lhs.push(rhs);
	}
	friend ostream &operator<<(ostream &lhs, const Stack &rhs) {
		vector<T> vec = *rhs.data;
		bool first = true;
		for (auto it = vec.begin(); it != vec.end(); ++it) {
			if (first) {
				first = false;
			} else {
				lhs << " ";
			}
			lhs << *it;
		}
		return lhs;
	}
	friend void operator>>(Stack &lhs, T &rhs) {
		rhs = lhs.pop();
	}
	friend bool operator++(Stack &ss) {
		return ss.full();
	}
	friend bool operator--(Stack &ss) {
		return ss.empty();
	}
};

#endif