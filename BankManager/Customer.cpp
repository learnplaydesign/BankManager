#include"Customer.h"

Customer::Customer()
{
	/* Ask user a number of question about the new customer */
	name = "empty";
	age = 0;
	address ="Empty";
	gender = "Empty";
	telNo = 0;
	
	std::string input = "";
	std::cout << "Customer Name?:";
	std::getline(std::cin, name);
	std::cout << "Customer Age?:";
	while(true)
	{
		std::getline(std::cin, input);
		std::stringstream errorCheck(input);
		if(errorCheck >> age)
			break;
		std::cout << "Invalid input" << std::endl;
	}
	std::cout << std::endl << "Customer Address?:";
	std::getline(std::cin, address);
	std::cout << std::endl << "Customer Gender?";
	std::getline(std::cin, gender);
	std::cout << std::endl << "Customer Telephone Number?:";
	
	// Stringstream allows the programme to check the input against the desired
	// variable  and if rejected will make user aware of invalid input preventing a cin loop
	while(true)
	{
		std::getline(std::cin, input);
		std::stringstream errorCheck(input);
		if(errorCheck >> telNo)
			break;
		std::cout << "Invalid input" << std::endl;
	}

}

Customer::~Customer()
{
	std::cout << " Deleting all accounts " << std::endl;
	accountStorage.deleteList();
}

/* Print's out all attributes of the customer */
void Customer::print(std::ostream &output)
{
	/* Called only by the Linked List this is used to show all of the information about the Customer
		and can also be used to output to a external file.
	*/
	output << " name: " << name
		   << " age: " << age
		   << " address: " << address  
		   << " gender: " << gender  
		   << " telNo: "  << telNo << std::endl;  
}

/* Main controsl for interacting with the customer*/
void Customer::displayOptions()
{
	int i= 0;
	int type = 0;
	bool run = true;
	std::string input = "";

	while(run)
	{
		std::cout << name << " Customer Menu" << std::endl
				  << "1. Add Account" << std::endl
				  << "2. Show Accounts" << std::endl
				  << "3. Account Transaction" << std::endl
				  << "4. Close Account" << std::endl
			      << "5. Change Details" << std::endl
				  << "6. Request Mortgage" << std::endl
				  << "7. Exit" << std::endl;
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
				/* 
					Allows user to select type of Account they want to make and have it created 
				*/

				std::cout << "Choose Account type:" << std::endl
						  << "1. Current Account" << std::endl
						  << "2. Junior Account" << std::endl
						  << "3. Corporate Savings" << std::endl
						  << "4. Student Savings" << std::endl;
				std::cin >> type;
				std::cin.sync();
	    		// Create a new current account
				
				if(addAccount(type))
				{
					type = 0;
					break;
				}
				else
				{
					std::cout << "ERROR: Account not created" << std::endl;
				}	
			
				i=0;
				break;

			case 2:
				// Show all Accounts and their balances
				accountStorage.showList();
				i=0;
				break;

			case 3:
				// Open the account to do a transaction
				std::cout << "Account Number?" << std::endl;
				getline(std::cin, input);
				std::cin.sync();
				accountStorage.openNode(input);
				i=0;
				break;

			case 4:
				// Delete an account
				std::cout << "Account Number?" << std::endl;
				getline(std::cin, input);
				std::cin.sync();
				accountStorage.removeNode(input);
				i=0;
				break;
			case 5:
				// Update Customer Details
				updateCustomerDetails();
			case 6:
				//Mortgage Request
				loan = new Loan();
			case 7:
				// Return to the main menu
				run = false;
				break;
		}	
				
	}
}

/* Update any information about the Customer*/
void Customer::updateCustomerDetails()
{
	std::string input = "";
	int command = 0;

	std::cout << "1. Change name" << std::endl
		      << "2. Change address" << std::endl
			  << "3. Change gender" << std::endl
			  << "4. change telNo" << std::endl;
				
	while(true)
	{
		std::getline(std::cin, input);
		std::stringstream errorCheck(input);
		if(errorCheck >> command)
			break;
		std::cout << "Invalid input" << std::endl;
	}
	
	// Using a switch statement to execture the correct command and save space
	switch(command)
	{
		case 1: 
			std::cout << "New name?:" << std::endl;
			std::getline(std::cin, name);
			break;
		case 2:
			std::cout << "New Address?:" << std::endl;
			std::getline(std::cin, address);
			break;
		case 3:
			std::cout << "New Gender?:" << std::endl;
			std::getline(std::cin, gender);
			break;
		case 4:
			while(true)
			{
				std::cout << "New Tel No?:" << std::endl;
				std::getline(std::cin, input);
				std::stringstream errorCheck(input);
				if(errorCheck >> telNo)
					break;
				std::cout << "Invalid input" << std::endl;
			}			
	}
}

/* Create a customer account */

bool Customer::addAccount(int option)
{
	Account* temp = NULL;

	switch(option)
	{
		case 1:
			temp = new CurrentAccount();
			return accountStorage.createNode((Object*)temp);
		case 2:
			if(age < 16)
			{
				temp = new JuniorAccount();
				return accountStorage.createNode((Object*)temp);
			}
			else
			{
				std::cout << "Customer to old" << std::endl;
				return false;
			}
		case 3:
			temp = new CorporateSavings();
			return accountStorage.createNode((Object*)temp);
		case 4:
			temp = new StudentSavings();
			return accountStorage.createNode((Object*)temp);
	} 
}
