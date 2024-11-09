
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string ReplaceWordInStringUsingBuildInFunction(string S1, string StringToReplace, string ReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace); //find next

	}

	return S1;
}

int main()
{
	
	string S1 = {"Welcome to Morocco, Morocco is a nice country" };
	string StringToReplace = "Morocco";
	string ReplaceTo = "USA";

	cout << left << setw(23) << "Original String " << setw(2) << ":";
	cout << setw(35) << S1 << endl;

	cout << setw(23) << "String After Replace " << setw(2) << ":";
	cout << setw(35) << ReplaceWordInStringUsingBuildInFunction(S1, StringToReplace, ReplaceTo) << endl;




}