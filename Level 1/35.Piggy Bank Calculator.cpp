
#include <iostream>
#include "clsInputValidate.h"

using namespace std;

struct stPiggyBankContent
{
	int Pennies = 0;
	int  Nickels = 0;
	int Dimes = 0;
	int Quarters = 0;
	int Dollars = 0;
};

stPiggyBankContent ReadPiggyBankContent()
{
	stPiggyBankContent PiggyBankContent;
	
	PiggyBankContent.Pennies = clsInputValidate<int>::ReadNumber("\nPlease Enter Total Pennies?");
	PiggyBankContent.Nickels = clsInputValidate<int>::ReadNumber("\nPlease Enter Total Nickels?");
	PiggyBankContent.Dimes = clsInputValidate<int>::ReadNumber("\nPlease Enter Total Dimes?");
	PiggyBankContent.Quarters = clsInputValidate<int>::ReadNumber("\nPlease Enter Total Quarters?");
	PiggyBankContent.Dollars = clsInputValidate<int>::ReadNumber("\nPlease Enter Total Dollars?");

	return PiggyBankContent;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBank)
{
	return PiggyBank.Pennies + (PiggyBank.Nickels * 5) + (PiggyBank.Dimes * 10) + 
		    (PiggyBank.Quarters * 25) + (PiggyBank.Dollars * 100);
}

int main()
{
	
	stPiggyBankContent PiggyBank = ReadPiggyBankContent();

	int TotalPennies = CalculateTotalPennies(PiggyBank);

	double TotalDollars = (double) TotalPennies / 100;

	cout << "\nTotal Pennies = " << TotalPennies << " Pennies\n";
	cout << "\nTotal Dollars = " << TotalDollars << " Dollars\n";
	
	system("pause>0");
	return 0;

}