#ifndef junioraccount_INCL_GUARD
#define junioraccount_INCL_GUARD

#include"Account.h"

/* Functionally the same as the Account prototype already set up */

class JuniorAccount : public Account
{
public:
	JuniorAccount();
    void print(std::ostream &output);
};

#endif