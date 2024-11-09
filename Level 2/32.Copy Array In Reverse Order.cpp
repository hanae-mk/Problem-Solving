

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
	cout << "Please enter array of elements ?" << endl;
	cin >> ArrayLength;
	
	for (int i = 0; i < ArrayLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

void CopyArrayInReverseOrder(int ArrSource[100], int ArrDestination[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
		
		ArrDestination[i] = ArrSource[ArrayLength - 1 - i];
		//0                   //10 - 1 -0 //9
		//1                   //10 - 1 - 1 //8
		//2                   //10 - 1 -2  //7 ....
		
	}
}

void PrintArray(int Arr[100], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << "\n";
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100] , ArrayLength;

	FillArrayWithRandomNumbers(Arr, ArrayLength);

	int Arr2[100];
	CopyArrayInReverseOrder(Arr, Arr2, ArrayLength);
	
	cout << "\nArray 1 elements : \n" << endl;
	PrintArray(Arr, ArrayLength);

	cout << "\n\nArray 2 elements after copying array 1 in reversed order : \n" << endl;
	PrintArray(Arr2, ArrayLength);
	
	cout << endl;

	return 0;

}