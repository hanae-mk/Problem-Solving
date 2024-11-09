
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vNames, string Delim)
{
	string S1 = "";

	for (string& s : vNames)
	{
		S1 += s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}


int main()
{
	vector <string> vNames = { "Mohammed","Hanae","Ali","Maher" };

	cout << "Vector After Join : \n";
	cout << JoinString(vNames, "###") << endl; 

	//Split String read string and returns a vector 
	//Join String  read vector and return string

	system("pause>0");

}

