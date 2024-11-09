
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
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);

		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			printf(" %0*d     ", 2, arr[i][j]);
			//cout << left << setw(3) << "     ";

		}
		cout << endl;
	}
}


void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];

		}
	}
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "\nMatrix 1 :\n" ;
	PrintMatrix(Matrix1, 3, 3);
	
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "\nMatrix 2 :\n";
	PrintMatrix(Matrix2, 3, 3);

	MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);

	cout << "\nResults :\n";
	PrintMatrix(MatrixResults, 3, 3);

	system("pause>0");

}