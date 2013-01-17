#include"CurrentAccount.h"

CurrentAccount::CurrentAccount()
{
	std::stringstream ss;
	accountType = "Current Account";
	balance = 0.0;
	creditLimit = 250;
	interestRate = 3;

	/*initialize random seed*/
	srand((unsigned int)time(NULL));
	
	/*Set account number*/
	accountNumber = rand() % 1000;
	ss << accountNumber;
	name = ss.str();
	taxExempt = false;
	
}

/* print relevant data to a output stream */
void CurrentAccount::print(std::ostream &output)
{
	output << " Account Number: " << name
			  << " Account Type: " << getAccountType() 
			  << " Balance: " << getBalance() << std::endl;
}