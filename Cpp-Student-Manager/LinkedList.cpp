#include "LinkedList.h"
#include "Student.h"
#include "Teacher.h"


template<typename T>
void List::add() {
	Person* tmp = new T();
	if (first == nullptr) {
		first = tmp;
		tail = tmp;
		return;
	}
	Person* iter = first;
	while (iter != nullptr) {
		if (tmp->getNeptun() == iter->getNeptun()) {
			delete tmp;
			std::cout << "Neptun already in use." << std::endl;
			return;
		}
		iter = iter->getNext();
	}
	tail->setNext(tmp);
	tail = tail->getNext();
	return;
}
// template function cannot be linked without these below
template void List::add<Student>();
template void List::add<Teacher>();


// took the idea from: https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
// had to figure out how to decide if an object belongs to a class or not
template<typename Base, typename T>
bool instanceOf(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}


void List::list(const std::function<void(Person*)>& function) {
	function(first);
	return;
}
void List::printList() {
	int choice;
	std::string input;
	std::cout << "Students\t-\t\t1" << std::endl;
	std::cout << "Teachers\t-\t\t2" << std::endl;
	std::cout << "All\t\t-\t\t3" << std::endl;
	std::getline(std::cin, input);
	choice = std::atoi(input.c_str());
	if (first == nullptr) {
		std::cout << "List is empty." << std::endl;
		return;
	}
	if (choice == 1) {
		auto lambda = [=](Person* iter) mutable {
			while (iter != nullptr) {
				if (instanceOf<Student>(iter)) {
					std::cout << *iter;
				}
				iter = iter->getNext();
			}
			return;
		};
		list(lambda);
	}
	else if (choice == 2) {
		auto lambda = [=](Person* iter) mutable {
			while (iter != nullptr) {
				if (instanceOf<Teacher>(iter)) {
					std::cout << *iter;
				}
				iter = iter->getNext();
			}
			return;
		};
		list(lambda);
	}
	else if (choice == 3) {
		auto lambda = [=](Person* iter) mutable {
			while (iter != nullptr) {
				std::cout << *iter;
				iter = iter->getNext();
			}
			return;
		};
		list(lambda);
	}
	else {
		std::cout << "Wrong input." << std::endl;
	}
}

void List::remove(const std::string& ne) {
	Person* iter = first;
	if (iter == nullptr) {
		std::cout << "List is empty." << std::endl;
		return;
	}
	else if (iter->getNext() == nullptr) {
		if (iter->getNeptun() == ne) {
			first = nullptr;
			tail = nullptr;
			delete iter;
			return;
		}
	}
	else {
		Person* lead = iter->getNext();
		if (iter->getNeptun() == ne) {
			first = iter->getNext();
			delete iter;
			return;
		}
		while (lead != nullptr) {
			if (lead->getNeptun() == ne) {
				iter->setNext(lead->getNext());
				if (lead->getNext() == nullptr) {
					tail = iter;
				}
				delete lead;
				return;
			}
			iter = lead;
			lead = lead->getNext();
		}
		return;
	}
}

void List::save() {
	Person* iter = first;
	std::ofstream oFile("registry.txt");
	if (!oFile.is_open()) {
		std::cout << "File didn't open." << std::endl;
	}
	while (iter != nullptr) {
		if (instanceOf<Student>(iter)) {
			oFile << "s," << iter->getName() << ',' << iter->getNeptun() << ',' << static_cast<Student*>(iter)->getCredits() << '\n';
		}
		else if (instanceOf<Teacher>(iter)) {
			oFile << "t," << iter->getName() << ',' << iter->getNeptun() << ',' << static_cast<Teacher*>(iter)->getTitle() << '\n';
		}
		iter = iter->getNext();
	}
	oFile.close();
}

void List::load() {
	std::ifstream iFile("registry.txt", std::ios::in);
	if (!iFile.is_open()) {
		std::cout << "File didn't open, or you opened the program for the first time." << std::endl;
	}
	std::string line;
	while (std::getline(iFile, line)) {
		std::stringstream ss(line);
		std::string component;
		std::vector<std::string> vec;
		vec.reserve(4);
		while (getline(ss, component, ',')) {
			vec.emplace_back(component);
		}
		if (vec.at(0) == "s") {
			Person* added = new Student(vec.at(1), vec.at(2), std::stoi(vec.at(3)));
			if (first == nullptr) {
				first = added;
				tail = added;
			}
			else {
				tail->setNext(added);
				tail = tail->getNext();
			}
		}
		else if (vec.at(0) == "t") {
			Person* added = new Teacher(vec.at(1), vec.at(2), vec.at(3));
			if (first == nullptr) {
				first = added;
				tail = added;
			}
			else {
				tail->setNext(added);
				tail = tail->getNext();
			}
		}
	}
}

List::~List() {
	if (first = nullptr) {
		return;
	}
	Person* del = first;
	Person* lead = first->getNext();
	while (lead != nullptr) {
		delete del;
		del = lead;
		lead = lead->getNext();
	}
	delete del;
	return;
}