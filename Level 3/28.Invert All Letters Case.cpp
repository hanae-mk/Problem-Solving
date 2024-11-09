

#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1;

	cout << "Please enter your string ?\n";
	getline(cin,S1);

	return S1;
}

char InvertLetterCase(char S1)
{
	return isupper(S1) ? tolower(S1) : toupper(S1);		
}

string InvertAllStringLetterCase(string S1)
{ 
	
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
		
	}

	return S1;
}
int main()
{
	string S1 = ReadString();

	cout << "\nString after Inverting All Letters Case : \n";
	S1 = InvertAllStringLetterCase(S1);
	cout << S1 << endl;

}