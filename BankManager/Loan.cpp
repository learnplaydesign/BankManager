#include"Loan.h"

Loan::Loan()
{
	getApproved();
}

// Gets the amount for the loan
void Loan::getAmount()
{
	std::string input ="";

	while(true)
	{
		std::getline(std::cin, input);
		std::stringstream errorCheck(input);
		if(errorCheck >> amount)
			break;
		std::cout << "Invalid input" << std::endl;
	}
}

double Loan::getMonthlyPayment()
{
	return amount/14;
}

bool Loan::getApproved()
{
	 int input = 0;

	std::cout << "How much does the customer require?" << std::endl;
	getAmount();

	std::cout << "Monthly Payment expected: " << getMonthlyPayment() << std::endl; 

	std::cout << "Customer accept mortgage terms?" << std::endl;
	std::cin >> input;
	std::cin.sync();

	switch(input)
	{
		case 1:
			std::cout << "Loan accepted" << std::endl;
			approved = true;
			return true;
		case 2:
			std::cout << "Loan request closed" << std::endl;
			approved = false;
			return false;
	}
}