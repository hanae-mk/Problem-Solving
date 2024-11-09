
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{ 

	cout << Message << endl;
	cin >> Number;

	} while (Number <= 0);

	return Number;
}

void PrintInvertedNumberPattern(int Number)
{
	
	cout << endl;

	for (int i = Number; i >= 1; i--) //kharejta men rasi s7iha w fahma dakshi
	{
		
		for (int j = 1 ; j <= i; j++) // had for loop b9it ghi kankharba9 fiha hta sd9et w dik j++ shufta men solution
		{
			cout << i ;
			
		}
             cout << endl;
	}
}

int main()
{
	PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number ?"));

	return 0;
}