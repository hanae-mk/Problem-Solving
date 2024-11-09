
#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void Swap(int& A, int& B)
{
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
}

void FillArrayWith1ToN(int Arr[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
		Arr[i] = i + 1;

}

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

void ShuffleArray(int Arr[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
		Swap(Arr[RandomNumber(1, ArrayLength) - 1] , Arr[RandomNumber(1, ArrayLength) - 1]);
	}

}

void PrintArray(int Array[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << " ";
	}

	cout << endl;
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100];
	int ArrayLength = ReadPositiveNumber("Please enter array of elements ?");

	FillArrayWith1ToN(Arr, ArrayLength);

    cout << "\nArray Elements Before Shuffle : \n";
	PrintArray(Arr, ArrayLength);

	ShuffleArray(Arr, ArrayLength);

	cout << "\nArray Elements After Shuffle : \n";
	PrintArray(Arr, ArrayLength);

	return 0;

}