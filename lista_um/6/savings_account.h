#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "account.h"

class SavingsAccount : public Account
{

private:
	float mRate;

public:
	explicit SavingsAccount(int number, float rate = 0.0005);
	void yield();
	const float rate() const;

	virtual const int type() const { return 'S'; }
	virtual void print() const;
};

#endif