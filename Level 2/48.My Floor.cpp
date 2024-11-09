

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

int MyFloor(float Num)
{
	if (Num > 0)
		return (int)Num;
	else
		return (int)Num - 1;

}
int main()
{
	float Number = ReadNumber();

	cout << "\nMy Floor Result : " << MyFloor(Number) << endl;
	cout << "\nC++ Floor Result : " << floor(Number) << endl;


}