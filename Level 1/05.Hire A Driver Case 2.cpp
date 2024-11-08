



#include <iostream>

using namespace std;

struct strInfo
{
	int Age;
	bool HasDriverLicense;
	bool HasRecommendation;
};

strInfo ReadInfo()
{
	strInfo Info;

	cout << "Please enter your age?\n";
	cin >> Info.Age;

	cout << "Do you have a driver license?\n";
	cin >> Info.HasDriverLicense;

	cout << "Do you have a recommendation?\n";
	cin >> Info.HasRecommendation;

	return Info;

}

bool IsAccepted(strInfo Info)
{
	if (Info.HasRecommendation)
	{ 
         return true ;
	}
	else
	{ 
		return (Info.Age > 21 && Info.HasDriverLicense);
    }
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