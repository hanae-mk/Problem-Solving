
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string ReadString()
{
	string S1 = " ";

	cout << "Please enter your string ?\n";
	getline(cin, S1);

	return S1;
}

bool IsVowel(char char1)
{
	char1 = tolower(char1);

	return ((char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u'));
}

void PrintVowelsInString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			cout << S1[i] << setw(6);
		}
	}
}

int main()
{
	string S1 =  ReadString();

	cout << "\nVowels In String are : ";
	PrintVowelsInString(S1);

	system("pause>0");

}