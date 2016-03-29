#include "savings_account.h"
#include <iostream>

SavingsAccount::SavingsAccount(int number, float rate):
	Account(number), mRate(rate)
{

}

void SavingsAccount::yield()
{
	credit(balance() * rate());
}

const float SavingsAccount::rate() const
{
	return mRate;
}

void SavingsAccount::print() const
{
	printf("[SAVINGS ACCOUNT] NUMBER: %d, BALANCE: R$ %.2f, RATE: %.4f\n", number(), balance(), rate());
}