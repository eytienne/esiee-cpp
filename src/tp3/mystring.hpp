#ifndef TP3_MYSTRING
#define TP3_MYSTRING

#include <string>
using namespace std;

class mystring {
  private:
	int len;
	mystring(int len, const char *data);

  protected:
	char *data;

  public:
	mystring(const char *init = "");
	mystring(const mystring &ms);
	~mystring();
	virtual string to_string() const;
	friend ostream &operator<<(ostream &lhs, const mystring &rhs) {
		return lhs << rhs.to_string();
	};
	void swap(mystring &rhs);
	template <typename T> mystring &operator=(const T &rhs);
	bool operator==(const mystring &rhs) const;
	mystring operator+(const mystring &rhs) const;
	const char &operator[](int idx) const;
	char &operator[](int idx);
};

#endif