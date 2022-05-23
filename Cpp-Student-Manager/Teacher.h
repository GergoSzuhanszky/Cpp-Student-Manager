#pragma once
#include "Person.h"

class Teacher : public Person {
	std::string title;
public:
	Teacher(const std::string& na, const std::string& ne, const std::string& ti)
		: Person(na, ne), title(ti) {}
	Teacher();
	std::string getTitle() { return title; }
	void write(std::ostream& out) const override;
	friend std::ostream& operator<<(std::ostream& out, const Teacher& t);
};