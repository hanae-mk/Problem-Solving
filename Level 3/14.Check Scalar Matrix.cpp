

#include <iostream>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << " " << arr[i][j] << "      ";
		}

		cout << "\n";
	}
}

bool IsScalarMatrix(int arr[3][3], short Rows, short Cols)
{
	
	int FirstDiagElement = arr[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if ((i == j) && arr[i][j] != FirstDiagElement)
			{
				return false;
			}
			if ((i != j) && arr[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{

	int Matrix1[3][3] = { {9,0,0} , {0,9,0} , {0,0,9} };

	cout << "\nMatrix 1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "\nYes : Matrix is scalar \n";
	else
		cout << "\nNo : Matrix is NOT scalar \n";

}