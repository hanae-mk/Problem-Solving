

#include <iostream>
#include <cstdlib>
using namespace std;

int ReadNumber(string Message)
{
	int Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;

}

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrLength)
{
	
	cout << "Please enter number of elements ?" << endl;
	cin >> ArrLength;

	for (int i = 0; i < ArrLength; i++)
		Arr[i] = RandomNumber(1, 100);
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
		cout << Arr[i] << " ";
}

short FindNumberPositionInArray(int Arr[100], int ArrLength, int Number)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (Number == Arr[i])
			return i;
	}

			return -1;
}

int main()
{

	srand(unsigned(time(NULL)));

	int Arr[100], ArrLength;

    FillArrayWithRandomNumbers(Arr, ArrLength);

	cout << "\nArray 1 elements : " << endl;
	PrintArray(Arr, ArrLength);

    int Number = ReadNumber("\nPlease enter a number to search for?");
	cout << "\nNumber you are looking for is : " << Number << endl;

	short NumberPosition = FindNumberPositionInArray(Arr, ArrLength, Number);

	if (NumberPosition == -1)
		cout << "The Number is not found :-(" << endl;
	else
	{
		cout << "\nNumber found at position : " << NumberPosition << endl;
		cout << "\nThe Number found its order : " << NumberPosition + 1 << endl;
	}


	return 0;
}