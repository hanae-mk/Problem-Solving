

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
	
	string sWord; //or token (Each word is a token)
	short pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{

		sWord = S1.substr(0, pos);

		if (sWord != "") //Not Equal Nothing
		{
			vString.push_back(sWord);//push back means add to vector
			
		}

		S1.erase(0, pos + Delim.length());

	}

	if (S1 != " ")
	{
		vString.push_back(S1);
		
	}

	return vString;
}

void PrintSplitString(vector <string>& vString)
{
	//Ranged Loop

	for (string& S : vString)
	{
		cout << S << endl;
	}
}

int main()
{
	vector <string> vString; //Local Variable Type string

	string S1 = ReadString();
	//string S2 = "Ali#,,#Maher#,,#Lama"; //#,,#

	vString = SplitString(S1, " "); //the result is stored in vstring

	cout << "\nTokens = " << vString.size() << endl; 

	PrintSplitString(vString);

	system("pause>0");

}