

#include <iostream>
#include <string>
using namespace std;

void FillArray(int Arr[100], int& ArrLength)
{
	ArrLength = 6;

	Arr[0] = 90;
	Arr[1] = 10;
	Arr[2] = 20;
	Arr[3] = 20;
	Arr[4] = 10;
	Arr[5] = 90;
}

void PrintArray(int Arr[100], int ArrLength)
{

	for (int i = 0; i < ArrLength; i++)
		cout << Arr[i] << " ";

	cout << "\n";

}

//int ReverseArray(int Arr[100], int ArrLength)
//{
//	for (int i = 0; i < ArrLength; i++)
//	{
//		ArrLength--;//5 //4 //3 //2 //1 //0
//		Arr[i] == Arr[ArrLength];
//		
//	}	
//}

bool IsPalindromeArray(int Arr[100], int ArrLength)
{
	//return ReverseArray(Arr, ArrLength) == true;
	for (int i = 0; i < ArrLength; i++)
	{
		ArrLength--;//5 //4 //3 //2 //1 //0
		if (Arr[i] != Arr[ArrLength]) 
		{
			return false;
		}
	}
	return true;
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrLength = 0;
	
	FillArray(Arr, ArrLength);

	cout << "Array Elements : \n";
	PrintArray(Arr, ArrLength);

	if (IsPalindromeArray(Arr, ArrLength))
		cout << "\nYes, array is palindrome\n";
	else
		cout << "\nNo, array is NOT palindrome\n";

	return 0;
}