
#include <iostream>
#include <cmath>
using namespace std;

enum enNumberType { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;

}

enNumberType CheckNumberType(int Number)
{

	int M = round(Number / 2); 

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enNumberType::NotPrime;

	}

	return enNumberType::Prime;

}

void PrintPrimeNumbersFrom1ToN(int Number)
{
	
	cout << "Prime Numbers From " << 1 << " To " << Number << " : " << endl;

	for (int i = 1; i <= Number; i++)
	{
		if ( CheckNumberType(i) == enNumberType::Prime)
		{
	     	cout << i << endl;
	    }
	}
}

int main()
{
	PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ? "));

	return 0;
	
}



