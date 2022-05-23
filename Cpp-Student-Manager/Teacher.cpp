#include "Teacher.h"

Teacher::Teacher() {
	std::string ti;
	std::cout << "Title:" << std::endl;
	getline(std::cin, ti);
	title = ti;
	_CREATED;
}

void Teacher::write(std::ostream& out) const {
	out << name << " " << neptun << " " << title << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Teacher& t) {
	t.write(out);
	return out;
}