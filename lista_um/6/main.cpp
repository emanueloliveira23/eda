#include <iostream>
#include "bank_account.h"
#include "savings_account.h"
#include "fidelity_account.h"
#include "linked_list_account.h"

void print(std::string);
void println();
void println(std::string);
void super_print(std::string);
void print_menu();
void read_menu_option(int*);
bool realy_want_exit();
void read_int(std::string, int*);
void read_float(std::string, float*);
void do_action(int, LinkedListAccount*);
void insert_new_account(Account*, LinkedListAccount*);
void insert_new_bank_account(LinkedListAccount*);
void insert_new_savings_account(LinkedListAccount*);
void insert_new_fidelity_account(LinkedListAccount*);
void do_credit(LinkedListAccount*);
void do_debit(LinkedListAccount*);
void see_balance_account(LinkedListAccount*);
void see_fidelity_bonus_account(LinkedListAccount*);
void do_transfer_between_accounts(LinkedListAccount*);
void yield_savings_account(LinkedListAccount*);
void yield_fidelity_account(LinkedListAccount*);
void remove_account(LinkedListAccount*);
void print_all_accounts(LinkedListAccount*);

int main(int argc, char const *argv[])
{
	int menu_option;
	LinkedListAccount *accounts = new LinkedListAccount();
	
	do {
		print_menu();
		read_menu_option(&menu_option);
		do_action(menu_option, accounts);
	} while(menu_option || !realy_want_exit());

	accounts->free();
	delete accounts;

	return 0;
}

void print(std::string data)
{
	std::cout << data;
}

void println() 
{
	println("");
}

void println(std::string data)
{
    std::cout << data << std::endl;
}

void super_print(std::string data)
{
	println("========================");
	  print("=== "); println(data);
	println("========================");
}

void print_menu() 
{
	println("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	println("$$ TOWER BANK - MONEY SECURITY $$");
	println("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	println();
	println("WHAT DO YOU WANT TO DO?");
	println("1 - CREATE BANK ACCOUNT");
	println("2 - CREATE SAVING ACCOUNT");
	println("3 - CREATE FIDELITY ACCOUNT");
	println("4 - DO CREDIT");
	println("5 - DO DEBIT");
	println("6 - SEE BALANCE");
	println("7 - SEE FIDELITY BONUS");
	println("8 - DO TRANSFER BETWEEN ACCOUNTS");
	println("9 - YIELD SAVINGS");
	println("10 - YIELD FIDELITY");
	println("11 - REMOVE ACCOUNT");
	println("12 - SEE ALL ACCOUNTS");
	println("0 - EXIT");
	println();
	print("PRESS THE MENU OPTION: ");
}

void read_menu_option(int * menu_option)
{
	std::cin >> (*menu_option);
}

bool realy_want_exit()
{
	print("YOU REALY WANT EXIT [y/N]? ");
	char d;
	std::cin >> d;
	return d == 'y' || d == 'Y';
}

void read_int(std::string field, int * value) {
	std::cout << "ENTER WITH " << field << ": ";
	std::cin >> (*value);
}

void read_float(std::string field, float* value) {
	std::cout << "ENTER WITH " << field << ": ";
	std::cin >> (*value);
}

void do_action(int menu_option, LinkedListAccount *accounts)
{
	switch (menu_option) {
		case 1: insert_new_bank_account(accounts); break;
		case 2: insert_new_savings_account(accounts); break;
		case 3: insert_new_fidelity_account(accounts); break;
		case 4: do_credit(accounts); break;
		case 5: do_debit(accounts); break;
		case 6: see_balance_account(accounts); break;
		case 7: see_fidelity_bonus_account(accounts); break;
		case 8: do_transfer_between_accounts(accounts); break;
		case 9: yield_savings_account(accounts); break;
		case 10: yield_fidelity_account(accounts); break;
		case 11: remove_account(accounts); break;
		case 12: print_all_accounts(accounts); break;
		case 0: break;
		default: println("INALID OPTION"); break;
	}

	println();
	println();
}

void insert_new_account(Account *account, LinkedListAccount *accounts)
{
	accounts->insert(account);
	super_print("ACCOUNT INSERTED");
	account->print();
	super_print("ACCOUNT INSERTED");
}

void insert_new_bank_account(LinkedListAccount *accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	BankAccount *bankAccount = new BankAccount(number);
	insert_new_account(bankAccount, accounts);
}

void insert_new_savings_account(LinkedListAccount *accounts)
{
	int number;
	float rate;

	read_int("NUMBER ACCOUNT", &number);
	read_float("RATE", &rate);

	SavingsAccount *savingsAccount = new SavingsAccount(number, rate);
	insert_new_account(savingsAccount, accounts);
}

void insert_new_fidelity_account(LinkedListAccount *accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	FidelityAccount *fidelityAccount = new FidelityAccount(number);
	insert_new_account(fidelityAccount, accounts);
}

void do_credit(LinkedListAccount* accounts)
{
	int number;
	float value;

	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		
		read_float("VALUE (R$)", &value);

		account->credit(value);

		super_print("CREDIT SUCCESS!");

	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}

void do_debit(LinkedListAccount* accounts)
{
	int number;
	float value;

	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		
		read_float("VALUE (R$)", &value);

		account->debit(value);

		super_print("DEBIT SUCCESS!");

	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}

void see_balance_account(LinkedListAccount* accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		super_print("ACCOUNT BALANCE");
		printf("R$ %.2f\n", account->balance());
		super_print("ACCOUNT BALANCE");
	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}

void see_fidelity_bonus_account(LinkedListAccount* accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		
		if (account->type() == 'F') {
			super_print("ACCOUNT BONUS");
			printf("R$ %.2f\n", ((FidelityAccount*) account)->bonus());	
			super_print("ACCOUNT BONUS");
		} else {
			super_print("ACCOUNT NOT IS FIDELITY");
		}
		
	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}

void do_transfer_between_accounts(LinkedListAccount* accounts)
{
	int source, target;
	float value;

	read_int("SOURCE NUMBER ACCOUNT", &source);

	Account *sourceAccount = accounts->search(source);
	
	if (sourceAccount == NULL) {
		super_print("SOURCE ACCOUNT NOT FOUND");
		return;
	}

	read_float("VALUE", &value);

	if (value > sourceAccount->balance()) {
		super_print("INSUFICIENTE BALANCE");
		return;
	}
	
	read_int("TARGET NUMBER ACCOUNT", &target);	
	
	Account *targetAccount = accounts->search(target);

	if (targetAccount == NULL) {
		super_print("TARGET ACCOUNT NOT FOUND");
		return;
	}

	sourceAccount->debit(value);
	targetAccount->credit(value);
	super_print("TRANSFER SUCCESS!");
}

void yield_savings_account(LinkedListAccount* accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		
		if (account->type() == 'S') {
			((SavingsAccount*) account)->yield();
			super_print("SAVINGS ACCOUNT YEILD");
			account->print();
			super_print("SAVINGS ACCOUNT YEILD");
		} else {
			super_print("ACCOUNT NOT IS SAVINGS");
		}
		
	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}


void yield_fidelity_account(LinkedListAccount* accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		
		if (account->type() == 'F') {
			((FidelityAccount*) account)->yield();
			super_print("FIDELITY ACCOUNT YEILD");
			account->print();
			super_print("FIDELITY ACCOUNT YEILD");
		} else {
			super_print("ACCOUNT NOT IS FIDELITY");
		}
		
	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}


void remove_account(LinkedListAccount* accounts)
{
	int number;
	read_int("NUMBER ACCOUNT", &number);

	Account *account = accounts->search(number);
	if (account != NULL) {
		accounts->remove(account);
		super_print("ACCOUNT REMOVED!");
	} else {
		super_print("ACCOUNT NOT FOUND!");
	}
}


void print_all_accounts(LinkedListAccount* accounts)
{
	super_print("LIST OF ACCOUNTS");
	accounts->print();
	super_print("LIST OF ACCOUNTS");
}