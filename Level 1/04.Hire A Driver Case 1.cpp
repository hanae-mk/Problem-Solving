

#include <iostream>

using namespace std;

struct strInfo
{
	int Age;
	bool HasDriverLicense;
};

strInfo ReadInfo()
{
	strInfo Info;

	cout << "Please enter your age?\n";
	cin >> Info.Age;

	cout << "Do you have a driver license?\n";
	cin >> Info.HasDriverLicense;

	return Info;

}

bool IsAccepted(strInfo Info)
{
	return (Info.Age > 21 && Info.HasDriverLicense);
}

void PrintResult(strInfo Info)
{
	if (IsAccepted(Info))
		cout << "Hired\n";
	else
		cout << "Rejected\n";
}
 
int main()
{

	 PrintResult(ReadInfo());

	return 0;

}