#ifndef object_INCL_GUARD
#define object_INCL_GUARD

#include<iostream>

class Object
{
	/*
		Object is extended from by Account and Customer
		this is for data storage use and to allow me 
		remove a bunch of items from memory in a list 
		all at once.
	*/
protected:
	std::string name;
public:
	Object(){};
	virtual ~Object(){};
	virtual void print(std::ostream &output){};
	virtual void displayOptions(){};
	virtual void destroy(){};
	virtual std::string getName(){return name;};
};

#endif 