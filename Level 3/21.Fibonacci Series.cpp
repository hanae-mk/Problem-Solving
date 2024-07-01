
#include <iostream>

using namespace std;

void PrintFibonacciSeries(short Number)
{
	int Prev1 = 1, Prev2 = 1, FibNumber = 0, Counter = 2;

	cout << "\n" << Prev1 << "  " << Prev2 << "  "; //1   1

	while (Counter < Number)
	{
		FibNumber = Prev1 + Prev2; //2
		cout << FibNumber << "  "; //2
		Prev2 = Prev1;   //1
		Prev1 = FibNumber; //2
		Counter++; 
	}
}

int main()
{	
	cout << "\nFibonacci Series :\n";
	PrintFibonacciSeries(10);

	system("pause>0");
	return 0;
}

