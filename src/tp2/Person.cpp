#include "./Person.hpp"

Person::Person(string lastname, string firstname, short age) {
	this->lastname = lastname;
	this->firstname = firstname;
	this->age = age;
};

Person::~Person() {}

string Person::getLastname() {
	return this->lastname;
}

void Person::setLastname(string lastname) {
	this->lastname = lastname;
}

string Person::getFirstname() {
	return this->firstname;
}

void Person::setFirstname(string firstname) {
	this->firstname = firstname;
}

short Person::getAge() {
	return this->age;
}

void Person::setAge(short age) {
	this->age = age;
}
