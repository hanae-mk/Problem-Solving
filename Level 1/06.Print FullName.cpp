

#include <iostream>
#include <string>

using namespace std;

struct strInfo
{
	string FirstName;
	string LastName;
};

strInfo ReadInfo()
{
	strInfo Info;

	cout << "Please enter your first name?\n";
	cin >> Info.FirstName;

	cout << "Please enter your last name?\n";
	cin.ignore(1, '\n');
	getline(cin, Info.LastName);

	return Info;

}

string GetFullName(strInfo Info , bool Reversed)
{
	string FullName;

	if (Reversed)
		FullName = Info.LastName + " " + Info.FirstName;
	else
	    FullName = Info.FirstName + " " + Info.LastName;

	return FullName;


}

void PrintFullName(string FullName)
{
	cout << "Your Full Name is : " << FullName << endl;
}

int main()
{
	PrintFullName(GetFullName(ReadInfo(),false)) ;

	return 0;
}