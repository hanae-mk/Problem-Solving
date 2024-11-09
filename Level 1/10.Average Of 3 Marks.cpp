

#include <iostream>
using namespace std;

void ReadNumbers(int& Mark1 , int& Mark2 , int& Mark3)
{

	cout << "Please enter Mark 1 ?\n";
	cin >> Mark1;

	cout << "Please enter Number 2 ?\n";
	cin >> Mark2;

	cout << "Please enter Number 3 ?\n";
	cin >> Mark3;

}

int SumOf3Marks(int Mark1 , int Mark2 , int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float) SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

void PrintResults(float Average)
{
	cout << "Total Of Numbers is : " << Average << endl;
}

int main()
{

	int Mark1 , Mark2 , Mark3;

	ReadNumbers(Mark1, Mark2, Mark3);

	PrintResults(CalculateAverage(Mark1, Mark2, Mark3));

	return 0;
}