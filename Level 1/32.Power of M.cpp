

#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

		cout << "Please enter a number?" << endl;
		cin >> Number;

	return Number;

}

int ReadPower()
{
	int Number;

		cout << "Please enter power of number? " << endl;
		cin >> Number;

	return Number;

}

int Power_Of_M (int Number , int M)
{
	if (M == 0)
	{
		return 1;
	}

	int P = 1;
	
	for (int Counter = 1; Counter <= M; Counter++)
	{
		 P *= Number;
	}

	return P;

}

int main()
{
	cout << " Result : " << Power_Of_M(ReadNumber(),ReadPower()) << "\n";

	return 0;







}