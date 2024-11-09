

#include <iostream>
using namespace std;

short RandomNumber(short From, short To)
{
	short RandNum = rand() % (To - From + 1) + From;
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

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				//continue;
				return false ;
			}						
		}

		//return 1;
	}
        //return 0;
	return true;
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "\nMatrix 1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes : Matrices are typical\n";
	else
		cout << "\nNo : Matrices are NOT typical\n";


	system("pause>0");


}

