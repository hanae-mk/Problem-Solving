

#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { CapitalLetter = 1, SmallLetter = 2, SpecialCharacter = 3, Digit = 4 };

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

	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
	case enCharType::Digit:
		return char(RandomNumber(48, 57));

	}
}

string GenerateWord(enCharType CharType, short Length)
{

	string word = "";

	for (int i = 1; i <= Length; i++)
	{
		word = word + GetRandomCharacter(CharType);

	}

	return word;
}

string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + " - ";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + " - ";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + " - ";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

	return Key;

}

void FillArrayWithKeys(string Array[100], int ArrLength)
{
	
	for (int i = 0; i < ArrLength; i++)
		Array[i] = GenerateKey();
	

}

void PrintStringArray(string Array[100], int ArrLength)
{

	cout << "\nArray Elements : " << endl;

	for (int i = 0; i < ArrLength; i++)
	{
		cout << "Array [" << i << "] : ";
		cout << Array[i] << endl;

	}

	cout << endl;
}

int main()
{

	srand(unsigned(time(NULL)));

	string Arr[100];
	int ArrLength = 0;

    ArrLength = ReadPositiveNumber("How many keys do you want to generate ?");

	FillArrayWithKeys(Arr, ArrLength);

	PrintStringArray(Arr, ArrLength);

	return 0;

}


