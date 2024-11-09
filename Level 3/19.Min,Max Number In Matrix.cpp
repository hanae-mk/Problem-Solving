//
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
////short RandomNumber(short From, short To)
////{
////	short RandNum = rand() % (To - From + 1) + From;
////	return RandNum;
////
////}
////
////void FillMatrixWithRandomNumbers(int Matrix1[3][3], short Rows, short Cols)
////{
////	
////	for (int i = 0; i < Rows; i++)
////	{
////		for (int j = 0; j < Cols; j++)
////		{
////			
////			Matrix1[i][j] = RandomNumber(1, 100);
////		}
////	}
////}
//
//void PrintMatrix(int Matrix1[3][3], short Rows, short Cols)
//{
//	for (int i = 0; i < Rows; i++)
//	{
//		for (int j = 0; j < Cols; j++)
//		{
//			cout << left << setw(3) << Matrix1[i][j] << "     ";
//		}
//
//		    cout << endl;
//	}
//}
//
//int FindMaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
//{
//	short MaxNumber = Matrix1[0][0];
//	
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//		
//			if (Matrix1[i][j] > MaxNumber)
//			{
//				MaxNumber = Matrix1[i][j];
//			}
//		}
//	}
//
//	return MaxNumber;
//}
//
//int FindMinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
//{
//	
//    short MinNumber = Matrix1[0][0]; 
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			
//			if (Matrix1[i][j] < MinNumber) 
//			{
//				MinNumber = Matrix1[i][j];
//			}
//		}
//	}
//
//	return MinNumber;
//}
//
//
//int main()
//{
//	
//	srand((unsigned)time(NULL));
//
//	int Matrix1[3][3] = { {77,5,12} , {22,20,6} , {14,3,9} };
//
//	//FillMatrixWithRandomNumbers(Matrix1, 3, 3);
//
//	cout << "\nMatrix 1 : \n";
//	PrintMatrix(Matrix1, 3, 3);
//
//	cout << "\nMin Number in matrix is : ";
//	cout << FindMinNumberInMatrix(Matrix1, 3, 3) << endl;
//	
//	cout << "\nMax Number in matrix is : ";
//	cout << FindMaxNumberInMatrix(Matrix1, 3, 3) << endl;
//
//	
//	system("pause>0");
//
//
//}



#include <iostream>
using namespace std;

void PrintFibonacciSeries()
{
	short Prev1 = 1, Prev2 = 1;
	short Sum = 0;

	for (int i = 1; i <= 10; i++)
	{

		//cout << Prev1 << "     ";
		//cout << Prev2 << "     ";
		Sum += Prev1 + Prev2;
		cout << Sum << "     ";
		Prev1 = Sum;
		Prev2 = Prev1;
		//cout << Prev1 + Prev2 << "    ";

	}
}

int main()
{
	PrintFibonacciSeries();
}