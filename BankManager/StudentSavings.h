#ifndef StudentSavings_INCL_GUARD
#define StudentSavings_INCL_GUARD

#include"Account.h"

/* Functionally the same as the Account prototype already set up */

class StudentSavings : public Account
{
public:
	StudentSavings();
	void print(std::ostream &output);
};

#endif