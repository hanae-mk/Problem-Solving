
#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{	 
	int Num = 0;
	
	cout << "Please enter a number ?" << endl;
	cin >> Num;

	return Num;
}

int MyAbs(int Num)
{
	if (Num < 0)
		return Num * (-1);
	else
		return Num;
}

//int C_Abs(int Num)
//{
//   return abs(Num);
//}

int main()
{
	int Num = ReadNumber();

	cout << "My abs result : " << MyAbs(Num) << endl;
	cout << "C++ abs result : " << abs(Num) << endl;
	

}