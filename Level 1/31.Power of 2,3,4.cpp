
#include <iostream>
using namespace std;

int ReadNumber(string Message)
{
	int Number;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

void PowerOf2_3_4(int Number)
{
	int a = Number * Number;
	int b = Number * Number * Number;
	int c = Number * Number * Number * Number;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

}

int main()
{
	PowerOf2_3_4(ReadNumber("Please enter a number?")) ;

	return 0;

}