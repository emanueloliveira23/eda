#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "account.h"

class BankAccount : public Account {

public:
	BankAccount(int number);

	virtual const int type() const { return 'B'; }
	virtual void print() const;
};

#endif