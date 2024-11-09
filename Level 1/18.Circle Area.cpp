

#include <iostream>
#include <cmath>

using namespace std;

float ReadRadious()
{
	float R;

	cout << "Please enter Radius R : \n";
	cin >> R;

	return R;

}

float CircleArea(float R)
{
	const float PI = 3.141592653589793238;

	float Area = PI * pow(R, 2);

	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	
	PrintResult(CircleArea(ReadRadious()));

	return 0;
}