#ifndef TP3_INTSTACK
#define TP3_INTSTACK

#include <vector>
using namespace std;

class IntStack {
  private:
	vector<int> *data;

  public:
	IntStack(int n = 20);
	IntStack(const IntStack &is);
	~IntStack();
	void push(int v);
	int pop();
	bool full();
	bool empty();
	friend void operator<(IntStack &lhs, const int &rhs);
	friend void operator>(IntStack &lhs, int &rhs);
};

#endif