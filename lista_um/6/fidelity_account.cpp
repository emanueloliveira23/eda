#include "fidelity_account.h"
#include <iostream>

FidelityAccount::FidelityAccount(int number):
	Account(number), mBonus(0.f)
{

}

const float FidelityAccount::bonus() const
{
	return mBonus;
}

void FidelityAccount::credit(float value) 
{
	float rate = value * 0.01;
	mBonus += rate;
	Account::credit(value);
}

void FidelityAccount::yield() 
{
	credit(mBonus);
	mBonus = 0.f;
}

void FidelityAccount::print() const
{
	printf("[FIDELITY ACCOUNT] NUMBER: %d, BALANCE: R$ %.2f, BONUS: R$ %.2f\n", number(), balance(), bonus());
}