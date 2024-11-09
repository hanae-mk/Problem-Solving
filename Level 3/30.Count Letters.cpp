
#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = " ";

	cout << "Please enter your string ?\n";
	getline(cin, S1);

	return S1;
}

char ReadCharacter()
{
	char char1 = ' ';

	cout << "\nPlease enter a character ?\n";
	cin >> char1;

	return char1;
}

short CountLetterInString(string S1, char Letter)
{
	
	short Counter = 0;
	
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();
	char char1 = ReadCharacter();

	cout << "\nLetter \'" << char1 << "\' Count = " << CountLetterInString(S1, char1) << endl;


}