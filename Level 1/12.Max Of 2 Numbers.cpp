

#include <iostream>

using namespace std;

void ReadNumbers(int& Number1, int& Number2)
{
	cout << "Please enter Number 1 : \n";
	cin >> Number1;

	cout << "Please enter Number 2 : \n";
	cin >> Number2;

}

int MaxOf2Numbers(int Number1, int Number2)
{
	if (Number1 > Number2)
		return Number1;
	else
		return Number2;
}

void PrintResults(int Max)
{
	cout << "Max Number is : " << Max << endl;
}

int main()
{
	int Number1, Number2;

	ReadNumbers(Number1, Number2);
	PrintResults(MaxOf2Numbers(Number1,Number2));

	return 0;
}
