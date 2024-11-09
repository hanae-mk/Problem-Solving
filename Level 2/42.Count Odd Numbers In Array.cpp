
// Problem 42 , 43 , 44 are so easy so I didn't keep a copy of them

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrayLength)
{

	cout << "Please enter length of array ?" << endl;
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)

		Arr[i] = RandomNumber(-100, 100);

}

void PrintArray(int Arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)

		cout << Arr[i] << " ";


	cout << "\n";
}

int CountNegativeNumbersInArray(int Arr[100], int ArrayLength)
{
	int Counter = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (Arr[i] <= 0)  
			Counter++;
	}
	return Counter;
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrayLength = 0;

	FillArrayWithRandomNumbers(Arr, ArrayLength);

	cout << "\nArray Elements : \n";
	PrintArray(Arr, ArrayLength);

	cout << "\nNegative numbers count is: ";
	cout << CountNegativeNumbersInArray(Arr,ArrayLength) << endl;

	return 0;
}