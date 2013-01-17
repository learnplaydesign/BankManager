#ifndef currentaccount_INCL_GUARD
#define currentaccount_INCL_GUARD

#include"Account.h"

/* Functionally the same as the Account prototype already set up */

class CurrentAccount : public Account
{
public:
	CurrentAccount();
	void print(std::ostream &output);
};

#endif