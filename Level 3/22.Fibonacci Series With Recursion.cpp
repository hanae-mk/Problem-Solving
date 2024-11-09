

#include <iostream>
using namespace std;

void PrintFibonacciUsingRecursion(short Number, short Prev1, short Prev2)
{
	int FibNumber = 0;
	
	cout << "1    ";

	if (Number > 0)
	{
		FibNumber = Prev1 + Prev2;
		Prev1 = FibNumber;
		Prev2 = Prev1;
		cout << FibNumber << "     ";
		PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);

		//Not Debuged
	}
}

int main()
{
	PrintFibonacciUsingRecursion(10 ,0 ,1);
}
