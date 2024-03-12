#include "pch.h"

#include "CreditCardAccount.h"
using namespace System;

int main(array<System::String ^> ^args)
{
    CreditCardAccount^ myaccount;
    myaccount = gcnew CreditCardAccount(12345, 2500);
    myaccount->SetCreditLimit(1000);
    myaccount->MakePurchase(1000);
    myaccount->MakeRepayment(700);
    myaccount->PrintStatement();
    long num = myaccount->GetAccountNumber();
    Console::Write("Account number: ");
    Console::WriteLine(num);
}
