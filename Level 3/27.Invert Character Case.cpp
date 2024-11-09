
#include <iostream>
#include <string>
using namespace std;

char ReadCharacter()
{
	char c = ' ';

	cout << "Please enter a character ?\n";
	cin >> c;

	return c;

}

char InvertCharacterCase(char c)
{
	return (isupper(c) ? tolower(c) : toupper(c));
	                      //true       //false
}

int main()
{
	char c = ReadCharacter();

	cout << "\nChar after inverting case : \n";
	c = InvertCharacterCase(c);
	cout << c << endl;


	system("pause>0");

}

