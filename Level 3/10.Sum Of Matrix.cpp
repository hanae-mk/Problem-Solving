
#include <iostream>
using namespace std;

short RandomNumber(short From, short To)
{
	short RandNum = rand() % (To - From + 1) + From;
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
	cout << "\nMatrix 1 : \n";
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d     ",2,arr[i][j]);

		}
		    cout << endl;
	}
}

short SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	
	short Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += Matrix1[i][j] ;

		}
	}

	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of Matrix 1 is : " << SumOfMatrix(Matrix1, 3, 3) << endl;


	system("pause>0");

}


