
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

float GetFrationPart(float Num)
{
	return Num - (int)Num;
	//nsit had function
}

int MyCeil(float Num)
{
	if (abs(GetFrationPart(Num)) > 0) //nsit abs
	{
      if (Num > 0)
		 return int(Num) + 1;
	  else
		  return (int)Num ;
	}

	return Num;
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Ceil Result : " << MyCeil(Number) << endl;
	cout << "\nC++ Ceil Result : " << ceil(Number) << endl;

	return 0;
}