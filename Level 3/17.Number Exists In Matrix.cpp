
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << " " << left << setw(3) << Matrix1[i][j] << "     ";
		}

		cout << "\n";
	}
}

bool IsNumberInMatrix(int Matrix1[3][3], short Number , short Rows, short Cols)
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

short CountNumberInMatrix(int Matrix1[3][3], short Number, short Rows, short Cols)
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
	return Counter;
}

int main()
{
	int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9} };
	short Number = 0;

	cout << "\nMatrix 1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nPlease enter the number to look for in matrix ? ";
	cin >> Number;

	if (IsNumberInMatrix(Matrix1, Number, 3, 3))
        cout << "\nYes, It is there\n";
	else
		cout << "\nNo, It is NOT there\n";

	//My Solution is 100% true like the teacher , I used the fastest method

	//The Slower Method:

	if (CountNumberInMatrix(Matrix1, Number, 3, 3))
		cout << "\nYes, It is there\n";
	else
		cout << "\nNo, It is NOT there\n";

	
}