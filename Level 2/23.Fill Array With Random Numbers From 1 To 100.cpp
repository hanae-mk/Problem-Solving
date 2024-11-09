

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

void ArrayWithRandomNumbersFrom1To100(int Arr[100], int& ArrayLength)
{

	cout << "Please enter Array Lenght : " << endl;
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
	{
		Arr[i] =  RandomNumber(0, 48);
	}

}

void PrintArray(int Arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], ArrayLength;

	ArrayWithRandomNumbersFrom1To100(Arr, ArrayLength);

	cout << "\nArray Elements : ";
	PrintArray(Arr, ArrayLength);

	return 0;

}