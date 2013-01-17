#ifndef Loan_INCL_GUARD
#define Loan_INCL_GUARD

#include <sstream>
#include<string>
#include<iostream>
class Loan
{
protected:
	double value;
	double amount;
	double mounthlyPayment;
	double surveyFee;
	bool approved;
public:
	Loan();
	void getAmount();
	double getMonthlyPayment();
	bool getApproved();

};

#endif