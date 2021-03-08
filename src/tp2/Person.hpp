#ifndef TP2_PERSON
#define TP2_PERSON

#include <sstream>
#include <string>
using namespace std;

class Person {
  private:
	string firstname, lastname;
	short age;

  public:
	Person(string lastname = "NULL", string firstname = "NULL", short age = 0);
	~Person();

	string getLastname();
	string getFirstname();
	short getAge();
	void setLastname(string lastname);
	void setFirstname(string firstname);
	void setAge(short age);

	string to_string() const {
		stringstream ret;
		ret << "Person{ firstname: " << this->firstname
			<< ", lastname: " << this->lastname << ", age: " << this->age
			<< " }";
		return ret.str();
	}

	friend ostream &operator<<(ostream &ss, const Person &pp) {
		return ss << pp.to_string();
	}
};

#endif