

#include <iostream>

using namespace std;

void ReadNumbers(int& Num1, int& Num2)
{
	cout << "Please enter Number A : \n";
	cin >> Num1;

	cout << "Please enter Number B : \n";
	cin >> Num2;

}

void SwapNumbers(int& A, int& B)
{
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
}

void PrintNumbers(int Num1, int Num2)
{
	cout << "\nNumber 1 = " << Num1 << endl;
	cout << "Number 2 = " << Num2 << endl;
}

int main()
{
	int Num1, Num2;

	ReadNumbers(Num1, Num2);

	PrintNumbers(Num1, Num2);

	SwapNumbers(Num1, Num2);

	PrintNumbers(Num1, Num2);

	return 0;

}