

#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << left << setw(3) << Matrix1[i][j] << "     ";
		}

		cout << endl;
	}
}

int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols / 2; j++)
		{
			if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
			{
				return false;
			}
		}
	}
	//Debuged
	return true;
}

int main()
{
	int Matrix1[3][3] = { {1,2,1} , {5,5,5} , {7,3,7} };

	cout << "\nMatrix 1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "\nYes : Matrix is Palindrome\n";
	else
		cout << "\nNo : Matrix is NOT Palindrome\n";

}