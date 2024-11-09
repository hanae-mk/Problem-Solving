
#include <iostream>
using namespace std;

void ReadTriangleData(float& A, float& B, float& C)
{
	cout << "Please enter side A : " << endl;
	cin >> A;

	cout << "Please enter base B : " << endl;
	cin >> B;

	cout << "Please enter side C : " << endl;
	cin >> C;

}

float CircleAreaByArbitraryTriangle(float A, float B, float C)
{
	const float PI = 3.141592653589793238;

	float P = (A + B + C) / 2;

	float X = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

	float Area = PI * pow(X, 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	float A, B, C;

	ReadTriangleData(A, B, C);

	PrintResult(CircleAreaByArbitraryTriangle(A, B, C));

	return 0;
}