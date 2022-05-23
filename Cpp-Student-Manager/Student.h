#pragma once
#include "Person.h"

class Student : public Person {
	unsigned int credits;
public:
	Student(const std::string& na, const std::string& ne, unsigned int cred)
		: Person(na, ne), credits(cred) {}
	Student();
	unsigned int getCredits() { return credits; }
	void write(std::ostream& out) const override;
	friend std::ostream& operator<<(std::ostream& out, const Student& s);
};