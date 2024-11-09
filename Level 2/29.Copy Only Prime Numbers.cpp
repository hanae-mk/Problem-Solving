

#include <iostream>
#include <cstdlib>
using namespace std;

enum enNumberType { Prime = 1, NotPrime = 2 };

enNumberType CheckNumberType(int Number)
{

	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enNumberType::NotPrime;

	}

	return enNumberType::Prime;
}

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrayLength)
{
	cout << "Please enter array length ? " << endl;
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

void CopyOnlyPrimeNumbers(int ArraySource[100], int ArrayDestination[100], int ArrayLength, int& Array2Length)
{
	
	int Counter = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckNumberType(ArraySource[i]) == enNumberType::Prime)
		{
			ArrayDestination[Counter] = ArraySource[i];
			Counter++;
		}
	}

	Array2Length = --Counter;
}

void PrintArray(int Arr[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arr[i] << " ";

	}
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrayLength;

	FillArrayWithRandomNumbers(Arr, ArrayLength);

	int Arr2[100], Array2Length = 0;
	CopyOnlyPrimeNumbers(Arr, Arr2, ArrayLength, Array2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(Arr, ArrayLength);

	cout << "\nPrime Numbers in Array 2 : \n";
	PrintArray(Arr2, Array2Length);

	return 0;

}