

#include <iostream>
#include <string>
using namespace std;

char ReadCharacter()
{
	char char1 = ' ';

	cout << "Please enter a charachter ?\n";
	cin >> char1;

	return char1;
}


bool IsVowel(char char1)
{
	char1 = tolower(char1);

	return ((char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u'));
}

int main()
{
	char char1 = ReadCharacter();

	if (IsVowel(char1))
		cout << "Yes : Letter \'" << char1 << "\' is vowel\n";
	else
		cout << "No : Letter \'" << char1 << "\' is NOT a vowel\n";

}

