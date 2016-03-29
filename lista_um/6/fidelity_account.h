#ifndef FIDELITY_ACCOUNT_H
#define FIDELITY_ACCOUNT_H

#include "account.h"

class FidelityAccount : public Account
{

private:
	float mBonus;

public:
	explicit FidelityAccount(int number);
	const float bonus() const;
	virtual void credit(float value);
	void yield();

	virtual void print() const;
	virtual const int type() const { return 'F'; }

};

#endif