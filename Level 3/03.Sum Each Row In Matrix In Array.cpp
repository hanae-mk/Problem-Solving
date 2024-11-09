

#include <iostream>
#include <iomanip>
using namespace std;

int RandomNum(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;

}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNum(1, 100);
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

		cout << endl;
	}
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	
	for (int j = 0; j < Cols; j++)             
	{                                          
		Sum += arr[RowNumber][j];              	
	}

	return Sum;
}

void SumMatrixRowsInArray(int arrSum[3], int arr[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{	
		arrSum[i] = RowSum(arr, i, Cols);
	}
}

void PrintRowsSumInArray(int arr[3], short Rows)
{
	
	cout << "\nThe following are the sum of each row in the matrix : \n";
	
	for (int i = 0; i < Rows; i++)
	{
		cout << "\nRow " << i + 1 << " Sum = " << arr[i] << endl;
		
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	PrintMatrix(arr, 3, 3);

	SumMatrixRowsInArray(arrSum, arr, 3, 3);

	PrintRowsSumInArray(arrSum, 3);
}