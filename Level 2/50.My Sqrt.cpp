
#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float Number = 0;

	cout << "Please enter a number ? \n";
	cin >> Number;

	return Number;
}

float MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	int Num = ReadNumber();

	cout << "My Sqrt function is : " << MySqrt(Num) << endl;
	cout << "C++ Sqrt function is : " << sqrt(Num) << endl;

	return 0;
}