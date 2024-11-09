

#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = "";

	cout << "Please enter your string ?\n";
	getline(cin, S1);

	return S1;
}

char ReadCharacter()
{
	char char1;

	cout << "\nPlease enter a character ?\n";
	cin >> char1;

	return char1;
}

char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

short CountLetter(string S1, char Letter, bool MatchCase = true)
{

	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		
		if (MatchCase) //Case Sensitive
		{
			if (S1[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Letter))//Here is the trick we convert the S1[i] and letter that the user entered to small or capital letters
				Counter++;                        //Case Insensitive
		}

	}

	return Counter;
}


int main()
{
	string S1 = ReadString();
	char char1 = ReadCharacter();

	cout << "\nLetter \'" << char1 << "\' Count = " << CountLetter(S1, char1) << endl;
	cout << "\nLetter \'" << char1 << "\'" << " Or " << "\'" << InvertLetterCase(char1) << "\'" << " Count = ";
	cout << CountLetter(S1, char1,false) << endl;

	//MatchCase is a default Parameter
	//Default in programmation means fail
    //Default Parameters = Optional Parameters

	system("pause>0");

}