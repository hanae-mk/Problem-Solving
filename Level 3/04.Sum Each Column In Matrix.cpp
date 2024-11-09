
#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;

}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	
	cout << "The following is a 3*3 random matrix : \n";
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << left << setw(3) << arr[i][j] << "     ";
		}
           
		    cout << "\n";
	}
	        
}

int SumColumnMatrix(int arr[3][3], short Rows, short ColNumber)
{
	
	int Sum = 0;

	for (int i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColNumber] ;
	}

	return Sum;
}

void PrintColumnsSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe following are the sum of each column in the matrix : \n";

	for (int j = 0; j < Cols; j++)
	{
		cout << "Col " << j + 1 <<" Sum : " << SumColumnMatrix(arr, Rows, j) << "\n";
	}
}

int main()
{
	
	srand((unsigned)time(NULL));
	int arr[3][3];
	
	FillMatrixWithRandomNumbers(arr, 3, 3);

	PrintMatrix(arr, 3, 3);

	PrintColumnsSum(arr, 3, 3);

	system("pause>0");

	return 0;

}