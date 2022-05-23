#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "Teacher.h"


int main() {
	bool end = false;
	List list;
	list.load();
	std::string input;
	while (!end) {
		int choice;
		std::cout << "Enter your choice:" << std::endl;
		std::cout << "Add\t\t-\t\t1" << std::endl;
		std::cout << "List\t\t-\t\t2" << std::endl;
		std::cout << "Remove\t\t-\t\t3" << std::endl;
		std::cout << "Exit\t\t-\t\t4" << std::endl;
		std::getline(std::cin, input);
		choice = std::atoi(input.c_str());
		std::string ne;
		switch (choice) {
		case 1:
			int person;
			std::cout << "Student\t\t-\t\t1" << std::endl;
			std::cout << "Teacher\t\t-\t\t2" << std::endl;
			std::cin >> input;
			person = std::atoi(input.c_str());
			std::cin.ignore();
			switch (person) {
			case 1:
				list.add<Student>();
				break;
			case 2:
				list.add<Teacher>();
				break;
			default:
				std::cout << "Wrong input." << std::endl;
				break;
			}
			list.save();
			break;
		case 2:
			list.printList();
			break;
		case 3:
			std::cout << "Neptun:" << std::endl;
			std::cin >> ne;
			list.remove(ne);
			std::cin.ignore(10000, '\n');
			list.save();
			break;
		case 4:
			end = true;
			break;
		default:
			std::cout << "Wrong input." << std::endl;
			break;
		}
	}
}