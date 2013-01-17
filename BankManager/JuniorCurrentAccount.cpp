#include"Account.h"
#include<time.h>
#include<sstream>

/* For debug and testing use only, otherwise use extended classes */

Account::Account()
{
	std::stringstream ss;
	
	accountType = "Default Account";
	balance = 0.0;
	creditLimit = 250;
	interestRate =5;

	/*initialize random seed*/
	srand((unsigned int)time(NULL));

	/*Set account number*/
	accountNumber = rand() % 1000;
	ss << accountNumber;
	name = ss.str();
}

// Inherited
void Account::displayOptions(){}
void Account::print(std::ostream &output)
{
	std::cout << "Account Number: " << accountNumber  
			  << " Account Type: " << accountType << std::endl;
}

double Account::showBalance(){return balance;}
void Account::addAmountToBalance(double deposit){}
void Account::setCreditLimit(double limit){creditLimit = limit;}
void Account::Withdraw(){}