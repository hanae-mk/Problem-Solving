

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> SplitString(string S1, string Delim)
{

	vector <string> vString;

	short pos = 0;
	string Token = "";

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		Token = S1.substr(0, pos);

		if (Token != "")
		{
			vString.push_back(Token);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(Token);
	}

	return vString;
}

string JoinString(vector <string> vString, string Delim)
{
	
	string S1;

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
	vector <string> vString = SplitString(S1, " ");

	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)// Jordan == Jordan 
			{
				s = ReplaceTo; //Joran = USA
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = ReplaceTo;
			}
		}
	}

	return JoinString(vString, " ");
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";

	cout << "\nOriginal String :\n";
	cout << S1 << endl;

	cout << "\nReplace with match case :\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo) << endl;

	cout << "\nReplace without match case :\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo,false) << endl;

	system("pause>0");

}