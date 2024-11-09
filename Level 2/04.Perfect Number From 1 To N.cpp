
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

bool IsPerfectNumber(int Number)
{
	int Sum = 0;

	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}

	return Number == Sum; 
}

void PrintResults(int Number) //PrintPerfectNumbersFrom1toN
{
	
	for (int j = 1; j <= Number; j++)
	{ 
		if (IsPerfectNumber(j))
		{
            cout << j <<  endl;
	    }
		
    }
}

int main()
{
	PrintResults(ReadPositiveNumber("Please enter a positive number ?"));
}