
#include <iostream>
using namespace std;

//Teacher Solution 
//My Solution was unsavaved :-(

void ReadNumbers(int Num[3])
{

	cout << "Please enter Number 1 ?\n";
	cin >> Num[0];

	cout << "Please enter Number 2 ?\n";
	cin >> Num[1];

	cout << "Please enter Number 3 ?\n";
	cin >> Num[2];

}

int SumOf3Numbers(int Num[3])
{
	return Num[0] + Num[1] + Num[2];
}

void PrintResults(int Total)
{
	cout << "Total Of Numbers is : " << Total << endl;
}

int main()
{
	
	int Num[3];

	ReadNumbers(Num);

	PrintResults(SumOf3Numbers(Num));

	return 0;
}