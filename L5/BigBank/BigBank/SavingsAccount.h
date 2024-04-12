#pragma once
#include "BankAccount.h"

ref class SavingsAccount : BankAccount {
public:
	SavingsAccount(String^ holder);
	static void SetInterestrate(double rate);
	static double GetInterestrate();
	virtual bool CanDebit(double amount) override;
private:
	static double interestrate;
};