
#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType{CapitalLetter = 1 , SmallLetter = 2 , SpecialCharacter = 3 , Digit = 4};

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;


	} while (Number <= 0);

	return Number;

}

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;

	return RandomNum;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enCharType::SmallLetter:
		return char(RandomNumber(97,122));

	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));

	case enCharType::Digit:
		return char(RandomNumber(48, 57));

	}
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++) //length = 4 
	{
		Word = Word + GetRandomCharacter(CharType);//A + B = AB + C = ABC ABC + D = ABCD
	}

	return Word; //ABCD
}

string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;

}

void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] : ";
		cout << GenerateKey() << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	
	GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate?"));


	return 0;
}

