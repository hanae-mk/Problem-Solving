

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrayLength)
{
	cout << "Please enter array length : " << endl;
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
	{
		/*cout << RandomNumber(1, 100) ;
		cin >> Arr[i];*/ //3yiiiiit mankhamem kifash kan3mlula walakin nsiiiit
		Arr[i] = RandomNumber(1, 100);
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

int SumArrayElements(int Arr[100], int ArrayLength)
{
	int Sum = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		Sum += Arr[i];
	}

	return Sum;
}

float AverageOfArrayElements(int Arr[100], int ArrayLength)
{
	//float Average = (float)SumArrayElements(Arr, ArrayLength) / ArrayLength;

	return (float) SumArrayElements(Arr, ArrayLength) / ArrayLength;
}

int main()
{

	srand((unsigned)time(NULL));

	int Arr[100], ArrayLength;

	FillArrayWithRandomNumbers(Arr, ArrayLength);

	cout << "\nArray Elements : ";
	PrintArray(Arr, ArrayLength);

	cout << "\nAverage of all numbers is : " << AverageOfArrayElements(Arr, ArrayLength) << endl;

	return 0;


}