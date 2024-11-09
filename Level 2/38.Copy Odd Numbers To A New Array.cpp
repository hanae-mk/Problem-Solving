


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

		Arr[i] = RandomNumber(1, 100);

}

void PrintArray(int Arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)

		cout << Arr[i] << " ";


	cout << "\n";
}

void AddArrayElement(int Number, int Arr[100], int& ArrLength)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number; //Arr[0] = 98 example
}

void CopyOddNumbers(int ArraySource[100], int ArrayDestination[100],
	                                int ArrayLength, int& ArrayDestinationLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
      if (ArraySource[i] % 2 != 0)

		   AddArrayElement(ArraySource[i], ArrayDestination,ArrayDestinationLength) ;
	
	}	
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrayLength = 0, Array2Length = 0;

	FillArrayWithRandomNumbers(Arr, ArrayLength);

	int Arr2[100];
	CopyOddNumbers(Arr, Arr2, ArrayLength, Array2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(Arr, ArrayLength);

	cout << "\nArray 2 odd numbers: \n";
	PrintArray(Arr2, Array2Length);

	return 0;
}