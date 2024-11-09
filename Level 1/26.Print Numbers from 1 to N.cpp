

#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a number? " << endl;
	cin >> Number;
	cout << endl;

	return Number;
}

void PrintNumbersFrom1ToN_UsingFor(int Number)
{
	cout << "Numbers printed using for loop : " << endl;
	
	for (int Counter = 1; Counter <= Number ; Counter++)
	{
		

		cout << Counter << endl;
	}
}

void PrintNumbersFrom1ToN_UsingWhile(int Number)
{
	int Counter = 0;

	cout << "Numbers printed using while loop : " << endl;

	while (Counter < Number)
	{
		Counter++;
		cout << Counter << endl;
		
	}
}

void PrintNumbersFrom1ToN_UsingDoWhile(int Number)
{
	int Counter = 0;

	cout << "Numbers printed using do ... while loop : " << endl;

	do
	{
		Counter++;
		cout << Counter << endl;
		
	} while (Counter < Number);
}

int main()
{
	int N = ReadNumber();

	PrintNumbersFrom1ToN_UsingFor(N);
	PrintNumbersFrom1ToN_UsingWhile(N);
	PrintNumbersFrom1ToN_UsingDoWhile(N);

	return 0;
}