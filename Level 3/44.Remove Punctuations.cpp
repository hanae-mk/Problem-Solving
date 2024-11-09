
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemovePunctuations(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;
}

int main()
{
	cout << "\nOriginal String : \n";
	string S1 = "Welcome To Jordan , Jordan 'is a nice country ; it's amazing.";
	cout << S1 << endl;

	cout << "\nPunctuations Removed : \n";
	cout << RemovePunctuations(S1) << endl;

}