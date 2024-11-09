
#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	
	string S1;

	cout << "Please enter your string ?\n";
	getline(cin, S1);

	return S1;
}

bool IsVowel(char char1)
{
    char1 = tolower(char1);

	return ((char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u'));
}

short CountVowelsInString(string S1)
{
	short Counter = 0;
	
	for (short i = 0; i < S1.length(); i++)
	{
		if (/*S1[i] ==*/ IsVowel(S1[i]))
			Counter++;
		
	}

	return Counter;
}

int main()
{
    
	string S1 = ReadString();

	cout << "\nNumber of vowels is : " << CountVowelsInString(S1) << endl;


}