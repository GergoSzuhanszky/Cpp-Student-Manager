#pragma once
#include <iostream>
#include <string>


#define _CONSTRUCTOR 1
#if _CONSTRUCTOR == 1 
#define _CREATED std::cout << "CREATED." << std::endl;
#endif

#define _DESTRUCTOR 1
#if _DESTRUCTOR == 1 
#define _DESTROYED std::cout << "DESTORYED." << std::endl;
#endif

class Person {
protected:
	std::string name;
	std::string neptun;
	Person* next;
public:
	Person();
	Person(const std::string& na, const std::string& ne)
		: name(na), neptun(ne), next(nullptr) {}
	Person* getNext();
	std::string getNeptun();
	std::string getName();
	void setNext(Person* p);
	virtual void write(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Person& p);
	virtual ~Person() { _DESTROYED; }
};