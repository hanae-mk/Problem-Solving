
#include <iostream>
#include <iomanip>
using namespace std;


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << " " << left << setw(3) << arr[i][j] << "    ";
		}
		cout << endl;
	}
}

bool IsNumberInMatrix(int Matrix1[3][3], int Number ,short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
				return true;
		}
	}

	return false;
}

void PrintInterSectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];

			if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
			{
				cout << Number << "    ";
			}
		}
	}
}

int main()
{
	int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9} };
	int Matrix2[3][3] = { {5,80,90} , {22,77,1} , {10,8,33} };

	cout << "\nMatrix 1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nInterSected Numbers are : ";
	PrintInterSectedNumbers(Matrix1, Matrix2, 3, 3);
	cout << endl;

	
}




