

#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNumber()
{
	int Number = 0;

	cout << "\nPlease enter a number ?\n";
	cin >> Number;

	return Number;
}

void AddArrayElement(int Number, int Arr[100], int& ArrLength)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void InputUserNumberInArray(int Arr[100], int& ArrLength)
{

	bool AddMore = true;

	do
	{
		AddArrayElement(ReadNumber(), Arr, ArrLength);

        cout << "\nDo you want to add more numbers? [0]:No,[1]:Yes? ";
		cin >> AddMore;

	} while (AddMore);
	
	
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
}

int main()
{
	int Arr[100], ArrLength = 0;
	InputUserNumberInArray(Arr, ArrLength);

	cout << "\nArray Length : " << ArrLength << endl;
	cout << "Array Element : ";
	PrintArray(Arr, ArrLength);

	return 0;
}