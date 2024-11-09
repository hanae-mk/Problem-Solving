
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

float LoanInstallment(float LoanAmount, float MonthlyPayment)
{

	return (float) LoanAmount / MonthlyPayment;

}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter loan amount?") ;
	float MonthlyPayment = ReadPositiveNumber("Please enter monthly payment?") ;

	cout << "\nTotal Months = " <<  LoanInstallment(LoanAmount, MonthlyPayment) << " Months";
	cout << endl;

	return 0;



}




	

	