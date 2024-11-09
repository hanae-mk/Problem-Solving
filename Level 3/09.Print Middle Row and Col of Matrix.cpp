

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
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);

		}
		cout << endl;
	}
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;

	for (int j = 0; j < Cols; j++)
	{
		printf(" %0*d    ", 2, arr[MiddleRow][j]);

	}
	cout << endl;
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;
	
	for (int i = 0; i < Rows; i++)
	{

		printf(" %0*d    ", 2, arr[i][MiddleCol]);
	}

	cout << endl;
}



int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "\nMatrix 1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Row of matrix 1 is : \n";
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Col of matrix 1 is : \n";
	PrintMiddleColOfMatrix(Matrix1, 3, 3);

	system("pause>0");

}