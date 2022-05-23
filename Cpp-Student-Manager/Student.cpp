#include "Student.h"

Student::Student() {
	unsigned int cred;
	std::cout << "Credits:" << std::endl;
	std::cin >> cred;
	credits = cred;
	std::cin.ignore();
	_CREATED;
}

void Student::write(std::ostream& out) const {
	out << name << " " << neptun << " " << credits << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
	s.write(out);
	return out;
}