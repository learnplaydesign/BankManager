#include"JuniorAccount.h"

JuniorAccount::JuniorAccount()
{
	std::stringstream ss;
	accountType = "Junior Account";
	balance = 0.0;
	creditLimit = 0;
	interestRate = 5;

	/*initialize random seed*/
	srand((unsigned int)time(NULL));
	
	/*Set account number*/
	accountNumber = rand() % 1000;
	ss << accountNumber;
	name = ss.str();
	taxExempt = true;
	
}

/* print relevant data to a output stream */
void JuniorAccount::print(std::ostream &output)
{
	output << " Account Number: " << name
			  << " Account Type: " << getAccountType() 
			  << " Balance: " << getBalance() << std::endl;
}