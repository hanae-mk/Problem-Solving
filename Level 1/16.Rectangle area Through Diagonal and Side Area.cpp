

#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(float& A, float& D)
{
	cout << "Please enter Number A : \n";
	cin >> A;

	cout << "Please enter Number D : \n";
	cin >> D;

}

float RectangleAreaBySideAndDiagonal(float A, float D)
{
	float Area = A * sqrt(pow(D, 2) - pow(A, 2));
	return Area;
}

void PrintResult(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
	float A, D;

	ReadNumbers(A, D);

	PrintResult(RectangleAreaBySideAndDiagonal(A, D));

	return 0;

}