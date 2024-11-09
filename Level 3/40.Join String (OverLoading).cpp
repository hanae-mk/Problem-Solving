
#include <iostream>
#include <string>
#include <vector>
using namespace std;


string JoinString(vector <string> vNames, string Delim)
{
	string S1 = "";

	for (string& s : vNames)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arrNames[], short Length, string Delim)
{
	string S1 = ""; //Local Variable

	for (short i = 0; i < Length; i++)   //for (string& s : arrNames) I used ranged loop but it's 
	{
		S1 = S1 + arrNames[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector <string> vNames = { "Mohammed","Hanae","Ali","Maher" };
    string arrNames[] = { "Mohammed","Hanae","Ali","Maher" };

	cout << "\nVector After Join : \n";
	cout << JoinString(vNames, " ");

	cout << "\n\nArray After Join : \n";
	cout << JoinString(arrNames, 4, " # ");

	system("pause>0");

}