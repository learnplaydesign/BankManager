#ifndef CorporateSavings_INCL_GUARD
#define CorporateSavings_INCL_GUARD

#include"Account.h"

/* Functionally the same as the Account prototype already set up */

class CorporateSavings : public Account
{
public:
	CorporateSavings();
	void print(std::ostream &output);
};

#endif