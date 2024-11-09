
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
			arr[i][j] = RandomNumber(0, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << left << setw(3) << arr[i][j] << "     ";
		}

		    cout << endl;
	}
}

short CountNumberInMatrix(int arr[3][3], short Number, short Rows, short Cols)
{
	short Counter = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
			{
				Counter++;
			}
		}	
	}
	  return Counter;

}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	short Number = 0;

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "\nMatrix 1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nEnter the number to count in matrix ?";
	cin >> Number;

	printf("\nNumber %d count in matrix is %d\n", Number, CountNumberInMatrix(Matrix1, Number,3, 3)); 

	//Same Result just modification in function name Check--->Count
}
