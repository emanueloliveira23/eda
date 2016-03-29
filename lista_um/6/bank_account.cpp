#include "bank_account.h"
#include <iostream>

BankAccount::BankAccount(int number):
	Account(number)
{

}

void BankAccount::print() const
{
	printf("[BANK ACCOUNT] NUMBER: %d, BALANCE: R$ %.2f\n", number(), balance());
}