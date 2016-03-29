#include "account.h"
#include <stdio.h>

Account::Account(int number):
	mNumber(number), mBalance(0)
{

}

void Account::credit(float value) 
{
	if (value > 0) {
		mBalance += value;
	}
}

bool Account::debit(float value) 
{
	if (mBalance >= value) {
		mBalance -= value;
		return true;
	} else {
		return false;
	}
}

const float Account::balance() const 
{
	return mBalance;
}

const int Account::number() const
{
	return mNumber;
}

void Account::print() const
{
	printf("TYPE: %c, NUMBER: %d, BALANCE: R$ %.2f\n", type(), number(), balance());
}

bool Account::operator==(const Account *other) const
{
	return other != NULL &&
		type() == other->type() && 
		number() == other->number();
}

bool Account::operator==(const Account &other) const
{
	return this == &other;
}