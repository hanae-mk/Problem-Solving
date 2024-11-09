
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
	
	return Number == Sum; //awel mara nxuf bhal had return
}

void PrintResults(int Number)
{
	if (IsPerfectNumber(Number))
		cout << Number << " is a perfect number" << endl;
	else
		cout << Number << " is not a perfect number" << endl;

}

int main()
{
	PrintResults(ReadPositiveNumber("Please enter a positive number ?"));
}