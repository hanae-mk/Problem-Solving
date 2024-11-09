

#include <iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;

}

float MonthlyInstallment(float LoanAmount, float TotalMonths)
{

	return (float)LoanAmount / TotalMonths;

}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter Loan Amount?");
	float TotalMonths = ReadPositiveNumber("Please enter Total Months?");

	cout << "\n Monthly Installment = " << MonthlyInstallment(LoanAmount, TotalMonths) << " Dollars";
	cout << endl;

	return 0;



}






