#pragma once
#include "LoyaltyScheme.h"

ref class CreditCardAccount {   
public:
    //literal System::String^ name = "Super Platinum Card";
    CreditCardAccount(long number, double limit);
    void SetCreditLimit(double amount);
    bool MakePurchase(double amount);
    void MakeRepayment(double amount);
    void PrintStatement();
    long GetAccountNumber();
    static int GetNumberOfAccounts();
    static CreditCardAccount();
    void RedeemLoyaltyPoints();


private:
    initonly long accountNumber;
    double currentBalance;
    double creditLimit;
    static double interesrRate;
    static int numberOfAccounts = 0;
    LoyaltyScheme^ scheme;
};

