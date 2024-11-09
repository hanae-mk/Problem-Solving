

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

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

void FillArrayWithRandomNumbers(int Arr[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
		Arr[i] = RandomNumber(1, 100);	
}

void SumOf2Arrays(int Arr[100], int Arr2[100], int ArraySum[100] ,int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
		ArraySum[i] = Arr[i] + Arr2[i] ;
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

	int Arr[100], Arr2[100] , ArraySum[100];
	int ArrayLength = ReadPositiveNumber("Please enter array length ?");

	FillArrayWithRandomNumbers(Arr, ArrayLength);
	FillArrayWithRandomNumbers(Arr2, ArrayLength);

	SumOf2Arrays(Arr, Arr2, ArraySum, ArrayLength);
	
	cout << "Array 1 elements : \n";
	PrintArray(Arr, ArrayLength);

	cout << "\nArray 2 elements : \n";
	PrintArray(Arr2, ArrayLength);

	cout << "\nSum of array 1 and array 2 elements : \n" ;
	PrintArray(ArraySum, ArrayLength);

	return 0;

}