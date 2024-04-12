#include "pch.h"
#include "SavingsAccount.h"

SavingsAccount :: SavingsAccount(String ^holder) : BankAccount(holder){}

void SavingsAccount::SetInterestrate(double rate) {
	interestrate = rate;
}

double SavingsAccount::GetInterestrate() {
	return interestrate;
}

bool SavingsAccount::CanDebit(double amount) {
	return (amount <= GetBalance() / 10);
}