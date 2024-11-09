
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string S1 = " ";

	cout << "Please enter your string ?\n";
	getline(cin, S1);

	return S1;
}

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
		vString.push_back(S1);
	}

	return vString;

}

string ReverseWordsInString(string S1)
{
	vector <string> vString;
	
	string S2 = "";

	vString = SplitString(S1, " ");

	//declare iterator
    vector <string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;
		S2+= *iter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1); //remove last space;
	
	return S2;

}

int main()
{
	string S1 = ReadString();

	cout << "\nString After reversing words : \n";
	cout << ReverseWordsInString(S1) << endl;

	system("pause>0");

}