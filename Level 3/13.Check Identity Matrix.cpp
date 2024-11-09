

#include <iostream>
using namespace std;


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "     ";
		}

		cout << "\n";
	}
}

bool IsIdentityMatrix(int arr[3][3], short Rows, short Cols)
{
	//int Counter = 0;

	//return (arr[Counter][Counter] && arr[Counter + 1][Counter + 1] && arr[Counter + 2][Counter + 2] == 1);

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != 1)
			{
				return false;
			}
			if (i != j && arr[i][j] != 0)
			{
				return false;
			}

		}
	}

	return true;
}
int main()
{
	srand((unsigned)time(NULL));

 // int Matrix1[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int Matrix1[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };
	
	cout << "\nMatrix 1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "\nYes : Matrix is identity\n";
	else
		cout << "\nNo : Matrix is NOT identity\n";



}