

#include <iostream>
#include <cmath>
using namespace std;

enum enNumberType { Prime = 1 , NotPrime = 2 };

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

enNumberType CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)

			return enNumberType::NotPrime;

	}

	return enNumberType::Prime;

}

void PrintNumberType(int Number)
{
	
	switch (CheckPrime(Number))
	{

	case enNumberType::Prime:
		cout << "The number is Prime\n";
		break;
	case enNumberType::NotPrime:
		cout << "The number is Not Prime\n";
		break;
	}
}

int main()
{
	
	PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));

	

	return 0;

}