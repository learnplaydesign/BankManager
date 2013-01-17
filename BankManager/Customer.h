#ifndef customer_INCL_GUARD
#define customer_INCL_GUARD
#include"Object.h"
#include"Account.h"
#include"CurrentAccount.h"
#include"JuniorAccount.h"
#include"CorporateSavings.h"
#include"StudentSavings.h"
#include"List.h"
#include"Loan.h"
#include <sstream>
#include<string>
#include<iostream>

/* 
	This is the customer class it extends from Object so that it's shared functions can be called.
	These include: Create, Destroy, displayOptions and Print.
*/

class Customer : public Object
{
	
private:
	//Attributes
	List accountStorage;
	std::string name;
	int age;
	std::string address;
	std::string gender;
	int telNo;
	Loan* loan;

public:
	Customer();
	~Customer();
	void print(std::ostream &output);
	std::string getName(){return name;}
	void displayOptions();
	void updateCustomerDetails();
	bool addAccount(int choice);

};

#endif