


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

void PrintNumbersFromNTo1_UsingFor(int Number)
{
	
	cout << "Numbers printed using for loop : " << endl;
 

	for (int Counter = Number ; Counter >= 1; Counter--)
	{


		cout << Counter << endl;
	}
}

void PrintNumbersFromNTo1_UsingWhile(int Number)
{
	int Counter = Number + 1; 

	cout << "Numbers printed using while loop : " << endl;

	while (Counter > 1)
	{

		Counter--;
		cout << Counter << endl;
        
	}
}

void PrintNumbersFromNTo1_UsingDoWhile(int Number)
{
	int Counter = Number + 1;

	cout << "Numbers printed using do ... while loop : " << endl;

	do
	{
		
		Counter--;
		cout << Counter << endl;
        

	} while (Counter > 1);
}

int main()
{
	int N = ReadNumber();

	PrintNumbersFromNTo1_UsingFor(N);
	PrintNumbersFromNTo1_UsingWhile(N);
	PrintNumbersFromNTo1_UsingDoWhile(N);

	return 0;
}