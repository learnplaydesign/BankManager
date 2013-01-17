#include"Account.h"


/* For debug and testing use only, otherwise use extended classes */

Account::Account()
{
	std::stringstream ss;
	accountType = "Default Account";
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
void Account::print(std::ostream &output)
{
	output << " Account Number: " << name
			  << " Account Type: " << accountType
			  << " Balance: " << balance << std::endl;
}

/* Main control function for the class display all options taken with the class */
void Account::displayOptions()
{
	time_t currentTime = time(0);
	struct tm * now = localtime( & currentTime );
	int i= 0;
	int type = 0;
	bool run = true;
	double amount;
	std::string input = "";
	while(run)
	{

		std::cout << name << " Account Menu" << std::endl
				  << "1. Withdraw" << std::endl
				  << "2. Deposit" << std::endl
				  << "3. Exit" << std::endl;
		while(true)
		{
			std::getline(std::cin, input);
			std::stringstream errorCheck(input);
			if(errorCheck >> i)
				break;
			std::cout << "Invalid input" << std::endl;
		}
		
		std::cin.sync();
		switch(i)
		{
			case 1:
				// Withdraw an amount after checking it isn't an illegal transaction
				logFile.open("log.txt",std::ios_base::app);				
				std::cout << "Enter amount to Withdraw" << std::endl;
				std::cin >> amount;
				std::cin.sync();
				Withdraw(amount);
				print(logFile);
				logFile << (now->tm_mday) << "/" << (now->tm_mon)
						<< " "
						<< (now->tm_hour)
						<< ":" << (now->tm_min);
				logFile << " Withdraw: " << amount << "\n";
				logFile.close();
				break;
			case 2:
				// Deposit an amount into the account
				logFile.open("log.txt",std::ios_base::app);
				std::cout << "Enter amount to Deposit" << std::endl;
				while(true)
				{	
					std::getline(std::cin, input);
					std::stringstream errorCheck(input);
					if(errorCheck >> amount)
						break;
					std::cout << "Invalid input" << std::endl;
				}
				deposit(amount);
				print(logFile);
				if(logFile.is_open())
				{

					logFile << (now->tm_mday) << "/" << (now->tm_mon)
							<< " "
							<< (now->tm_hour)
							<< ":" << "0" <<(now->tm_min);
					logFile << " Deposit: " << amount << "\n";
					logFile.close();
				}
				else
				{
					std::cout << "LOG CLOSED";
				}
				break;
			case 3:
				// Return to the customer interface
				run = false;
				break;
		}	
				
	}


}

/* Change the credit limit of the account only used from displayOptions */

void Account::setCreditLimit(double limit)
{
	creditLimit = limit;
}

/* Returns the balance of the account */

double Account::getBalance()
{
	return balance;
}

/* Returns the account type */
std::string Account::getAccountType()
{
	return accountType;
}


/* Deposits money into the account */

void Account::deposit(double deposit)
{
	balance += deposit;
}

// Takes an amount which it then compares to the current balance and if true subtracts from it. If false logs an error.
void Account::Withdraw(double amount)
{
	if(amount < (getBalance()+creditLimit))
	{
		balance -= amount;
	}
	else
	{
		std::cout << "Incorrect Funds" << std::endl;
		logFile << "Error not enough funds to withdraw \n";
	}
}