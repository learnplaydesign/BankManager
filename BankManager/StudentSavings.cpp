#include"StudentSavings.h"

StudentSavings::StudentSavings()
{
	std::stringstream ss;
	accountType = "StudentSavings";
	balance = 0.0;
	creditLimit = 250;
	interestRate = 10;

	/*initialize random seed*/
	srand((unsigned int)time(NULL));
	
	/*Set account number*/
	accountNumber = rand() % 1000;
	ss << accountNumber;
	name = ss.str();
	taxExempt = true;
	
}

/* print relevant data to a output stream */
void StudentSavings::print(std::ostream &output)
{
	output << " Account Number: " << name
			  << " Account Type: " << getAccountType() 
			  << " Balance: " << getBalance() << std::endl;
}