

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrayLenght)
{
	cout << "Please enter array lenght ? " << endl;
	cin >> ArrayLenght;

	for (int i = 0; i < ArrayLenght; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}

}

void PrintArray(int Arr[100], int ArrayLenght)
{

	for (int i = 0; i < ArrayLenght; i++)
	{

		cout << Arr[i] << " ";

	}

	cout << "\n";
}

int MaxNumber(int Arr[100], int ArrayLenght)
{
	
	int Max = 0;

	for (int i = 0; i < ArrayLenght; i++)
	{
		if (Arr[i] > Max) 
		{

          Max = Arr[i]; 

		}
			
	}

	return Max;
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrayLenght;

	FillArrayWithRandomNumbers(Arr, ArrayLenght);

	cout << "\nArray Elements : ";
	PrintArray(Arr, ArrayLenght);

	cout << "\nMax Number is : " << MaxNumber(Arr, ArrayLenght) << endl;

	return 0;
}