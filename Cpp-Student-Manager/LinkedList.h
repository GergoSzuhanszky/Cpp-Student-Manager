#pragma once
#include <vector>
#include <sstream>
#include <functional>
#include <fstream>
#include <ios>
#include "Person.h"

class List {
	Person* first;
	Person* tail;
	std::fstream File;
public:
	List()
		: first(nullptr), tail(nullptr), File("registry.txt") {}
	template<typename T>
	void add();
	void list(const std::function<void(Person*)>& function);
	void printList();
	void remove(const std::string&);
	void load();
	void save();
	~List();
};