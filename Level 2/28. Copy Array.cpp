

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
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

void PrintRandomArray(int Arr[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << "\n";
}

void CopyArray(int ArraySource[100], int ArrayDestination[100], int ArrayLength)
{
	
	for (int i = 0; i < ArrayLength; i++)
		ArrayDestination[i] = ArraySource[i] ;
	
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrayLength ;

	FillArrayWithRandomNumbers(Arr, ArrayLength);

	int Arr2[100];
	CopyArray(Arr, Arr2, ArrayLength);
	       //  |      |   
	      //source  //destination
	cout << "\nArray 1 elements : ";
	PrintRandomArray(Arr, ArrayLength);

	cout << "\nArray 2 elements after copy: ";
	PrintRandomArray(Arr2, ArrayLength);

	return 0;
}