#include"CorporateSavings.h"

CorporateSavings::CorporateSavings()
{
	std::stringstream ss;
	accountType = "Corporate Savings";
	balance = 0.0;
	creditLimit = 500;
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
void CorporateSavings::print(std::ostream &output)
{
	output << " Account Number: " << name
			  << " Account Type: " << getAccountType() 
			  << " Balance: " << getBalance() << std::endl;
}
