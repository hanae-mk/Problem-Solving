

#include <iostream>
using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;

	cout << "Please enter a number? " << endl;
	cin >> Number;

	return Number;
}

enOddOrEven CheckOddOrEven(int Counter)
{
	if (Counter % 2 != 0)
		return enOddOrEven::Odd;
	else 
		return enOddOrEven::Even;


}

int SumOddNumbersFrom1ToN_UsingFor(int Number)
{
	int Sum = 0;

	cout << "Numbers printed using for loop : " << endl;

	for (int Counter = 1; Counter <= Number; Counter++)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
			Sum += Counter;
		}
	}
	return Sum;
}

int SumOddNumbersFrom1ToN_UsingWhileLoop(int Number)
{
	int Counter = 0;
	int Sum = 0;

	cout << "Numbers printed using while loop : " << endl;

	while (Counter < Number)
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
           Sum += Counter;
		}

	}
	return Sum ;
}

int SumOddNumbersFrom1ToN_UsingDoWhileLoop(int Number)
{
	int Counter = 0;
	int Sum = 0;

	cout << "Numbers printed using do while loop : " << endl;

	do 
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
			Sum += Counter;
		}

	} while (Counter < Number);

	return Sum;
}

int main()
{
	int N = ReadNumber();

	cout << SumOddNumbersFrom1ToN_UsingWhileLoop(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingFor(N) << endl;
	cout << SumOddNumbersFrom1ToN_UsingDoWhileLoop(N) << endl;
}