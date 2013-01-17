#include"List.h"
#include"Account.h"
#include"Customer.h"
#include<sstream>
#include<string>
#include<iostream>
#include <fstream>
#include<string>
#include<Windows.h>
using namespace std;

List customerStorage;
ifstream logFile;
/* 
*	Returns true if the customer is added to the list. 
*/
bool newCustomer()
{
	Customer* temp = new Customer();
	return customerStorage.createNode((Object*)temp);
}

void main(void)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);

	int i= 0;
	string name;
	std::string input = "";

	while(true)
	{
		cout << "Main Menu" << endl
		 << "1. Add Customer" << endl
		 << "2. Show List" << endl
		 << "3. Select Customer" << endl
		 << "4. Remove Customer" << endl
		<< "5. Managers Log" << endl;
		while(true)
		{
			getline(cin, input);
			stringstream errorCheck(input);
			if(errorCheck >> i)
				break;
			cout << "Invalid input" << std::endl;
		}
		cin.sync();
		switch(i)
		{
			case 1:
				/* Call New Customer function */
				if(newCustomer())
				{
					i = 0;
					break;
				}
				else
				{
					cout << "ERROR:failure to add customer";
				}	
			case 2:
				/* List all Customers */
				customerStorage.showList();
				i=0;
				break;
			case 3:
				/*Select a customer*/
				cout << "Customer Name?" << endl;
				getline(cin, name);
				cin.sync();
				customerStorage.openNode(name);
				break;
			case 4:
				/* Remove a customer */
				cout << "Customer Name?" << endl;
				getline(cin, name);
				cin.sync();
				customerStorage.removeNode(name);
				break;
			case 5:

				/* Managers Log */
				string line;
				logFile.open("log.txt");
				if (logFile.is_open())
				  {
					while ( logFile.good() )
					{
					  getline (logFile,line);
					  cout << line << endl;
					}
					logFile.close();
				  }
		}	
				
	}
}

