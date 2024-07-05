//Hanae Messari Khali
#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

template <class T>

class clsUtil
{
public:

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, SpecialCharacter = 4, Mix = 5 };
	enum enNumberType { Prime = 1, NotPrime = 2 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static T RandomNumber(T From, T To)
	{
		T RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == Mix)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));
		default:
			return char(RandomNumber(65, 90));
		}
	}

	static string GenerateWord(enCharType CharType, int Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;

	}

	static void GenerateKeys(int NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(T& A, T& B)
	{
		T Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static void ShuffleArray(int Arr[100], int ArrayLength)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrayLength) - 1], Arr[RandomNumber(1, ArrayLength) - 1]);
		}

	}

	static void ShuffleArray(string Arr[100], int ArrayLength)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrayLength) - 1], Arr[RandomNumber(1, ArrayLength) - 1]);
		}

	}

	static void FillArrayWithRandomNumbers(int Arr[100], int ArrayLength, int From, int To)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = RandomNumber(From, To);
		}

	}

	static void FillArrayWithRandomWords(string Arr[100], int ArrayLength, enCharType CharType, short WordLength)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = GenerateWord(CharType, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string Arr[100], int ArrayLength, enCharType CharType)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = GenerateKey(CharType);
		}

	}

	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i <= NumberOfTabs; i++)
		{
			t += "\t";
		}

		return t;
	}

	static string EncryptText(string Text, short EncryptionKey) //jcpcg
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char(Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey) //hanae
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char(Text[i] - EncryptionKey);
		}

		return Text;
	}

	static T ReverseNumber(T Number)
	{
		T Remainder = 0, Number2 = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;

	}

	static short CountDigitFrequency(int Number, short DigitToCheck)
	{
		short Remainder = 0, FreqCount = 0;

		while (Number > 0) 
		{
			Remainder = Number % 10; 
			Number = Number / 10; 

			if (Remainder == DigitToCheck)
			{
				FreqCount++;
			}
		}

		return FreqCount;
	}

	static enNumberType CheckNumberType(int Number)
	{

		int M = round(Number / 2);

		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enNumberType::NotPrime;
		}

		return enNumberType::Prime;

	}

};
