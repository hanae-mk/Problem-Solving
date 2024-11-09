

#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix1[i][j] << "     ";
		}
		cout << endl;
	}
}

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				Counter++;
			}
		}
	}
	return Counter ;
}

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;

	return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ((float)MatrixSize / 2));//9 / 2 = 4.5 ---> 5
}

int main()
{
	int Matrix1[3][3] = { {0,0,12}, {0,0,1}, {0,0,9} };

	PrintMatrix(Matrix1, 3, 3);

	if (IsSparseMatrix(Matrix1, 3, 3))
	{
		cout << "\nYes : It is a Spare Matrix\n";
	}
	else
	{
		cout << "\nNo : It is NOT a Spare Matrix\n";
	}

	system("pause > 0");

}