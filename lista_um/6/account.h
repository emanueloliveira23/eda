#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

private:
	float mBalance;
	int mNumber;

protected:
	explicit Account(int number);

public:
	virtual void credit(float value);
	virtual bool debit(float value);
	virtual const int type() const = 0;
	virtual void print() const;
	const float balance() const;
	const int number() const;
	bool operator==(const Account *other) const;
	bool operator==(const Account &other) const;

};

#endif