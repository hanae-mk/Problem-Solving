

#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;

	cout << "Please enter age : \n";
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{

	return ( Number >= From && Number <= To);
}

void PrintResult(int Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
		cout << Age << " is a valid age" << endl;
	else
		cout << Age << " is invalid age" << endl;

}

int main()
{

	PrintResult(ReadAge()) ;

	return 0;
}