
#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float Num = 0;

	cout << "Please enter a number ?\n";
	cin >> Num;

	return Num;
}

float GetFractionalPart(float Num)
{
	return Num - int(Num); //-10.7 - 10 = -0.7
}

int MyRound(float Num)
{
	if (Num > 0)  //12.2
		if (GetFractionalPart(Num) >= 0.5)
		return ++Num; //Num + 1
	else
		return Num;

	if (Num < 0)  //-10.7
		if (GetFractionalPart(Num) <= - 0.5)
			return --Num; //Num - 1
		else
			return Num;
	//My Solution
}

int MyRound1(float Num)
{
	int IntegerPart ;
	IntegerPart = (int)Num;

	float FractionPart = GetFractionalPart(Num);

	if (abs(FractionPart) >= .5)
	{
		if (Num > 0)
			return ++IntegerPart;
		else
			return --IntegerPart;
	}
	else
	{
		return IntegerPart;
	}
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Round Result : " << MyRound1(Number) << endl;
	cout << "\nC++ Round Result : " << round(Number) << endl;
	
	
}