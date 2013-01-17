#ifndef account_INCL_GUARD
#define account_INCL_GUARD

#include"Object.h"
#include<iostream>
#include<fstream>
#include<time.h>
#include<sstream>


/* This is the base Account Class that is extended from in the functional classes
	I use this class to set out the rules for the simple functions.
*/

class Account : public Object
{
protected:
	int accountNumber;
	bool taxExempt;
	double balance;
	double creditLimit;
	int interestRate;
	std::ofstream logFile;
	std::string accountType;

public:
	Account();
	virtual void print(std::ostream &output);
	virtual void displayOptions();
	virtual std::string getAccountType();
	virtual double getBalance();
	virtual void deposit(double deposit);
	virtual void setCreditLimit(double limit);
	virtual void Withdraw(double amount);
};

#endif 