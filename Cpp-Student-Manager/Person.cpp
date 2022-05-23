#include "Person.h"

Person::Person() {
	std::string na;
	std::string ne;
	std::cout << "Name:" << std::endl;;
	std::getline(std::cin, na);
	std::cout << "Neptun:" << std::endl;
	std::getline(std::cin, ne);
	name = na;
	neptun = ne;
	next = nullptr;
}

Person* Person::getNext() {
	if (this == nullptr)
		return nullptr;
	return next;
}

std::string Person::getNeptun() {
	return neptun;
}

std::string Person::getName() {
	return name;
}

void Person::setNext(Person* p) {
	next = p;
}

void Person::write(std::ostream& out) const {
	out << name << " " << neptun << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
	p.write(out);
	return out;
}