#pragma once 
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:

	string _Value = "";

public:

	clsString() //Default Constructor if I make an object type clsString class and I didn't sent anything as parameter so it's returns empty "".
	{
		_Value = "";
	}

	clsString(string Value) //Parameterized Contructor
	{
		_Value = Value;
	}

	//Every Property have 3 things : set function, get function and declaration specification
	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue() //GetValue
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

	//This Static Member Function is a shared Function to all classes 
	//we can call it without having an object
	//We can use it generally
	//Doesn't Affect the object
	static short CountWords(string S1)
	{
		string delim = " ";
		short pos = 0;
		string sword;
		short Counter = 0;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sword = S1.substr(0, pos);

			if (sword != " ")
			{
				Counter++;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}

	//Affect the object
	short CountWords()
	{
		return CountWords(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		//no need to return value, this function will directly update the object value
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	//We have just the static method because if the user would the invert a letter he call 
	//only the class not the object because the object should have a string not just a charachter
	static char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string InvertAllLettersCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				S1[i] = InvertLetterCase(S1[i]);
			}
		}

		return S1;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 3 }; //You can add enums in your class

	static short CountLetters(string S1, enWhatToCount WhatToCount)
	{
		if (WhatToCount == enWhatToCount::All)
			return S1.length();

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			{
				Counter++;
			}

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}

	short CountLetters()
	{
		return CountLetters(_Value, enWhatToCount::All);
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
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

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	//We have just the static method because if the user would the invert a letter he call 
	//only the class not the object because the object should have a string not just a charachter
	static bool IsVowel(char char1)
	{
		char1 = tolower(char1);

		return ((char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u'));
	}

	static short CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static vector <string> Split(string S1, string Delim)
	{
		vector <string> vString;
		string sWord; //or token (Each word is a token)
		short pos = 0;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{

			sWord = S1.substr(0, pos);

			if (sWord != "") //Not Equal Nothing
			{
				vString.push_back(sWord);//push back means add to vector

			}

			S1.erase(0, pos + Delim.length());

		}

		if (S1 != " ")
		{
			vString.push_back(S1);
		}

		return vString;
	}

	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimLeft(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}

		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}

		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));

	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	//In these 2 functions Join String we only made static functions because there is nothing inside 
	//object I would make joining we usually receive array or vector to make join string and not string
	static string JoinString(vector <string> vString, string Delim)
	{
		string S1 = "";

		for (string& s : vString)
		{
			S1 += s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = ""; //Local Variable

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1)
	{
		vector <string> vString;

		string S2 = "";

		vString = Split(S1, " ");

		//declare iterator
		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space;

		return S2;

	}

	void ReverseWordsInString() //Every Time you see void, that means that you will modify the value of object itself
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string ReplaceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = S1.find(StringToReplace); //find next

		}

		return S1;
	}

	string ReplaceWord(string StringToReplace, string ReplaceTo) //I don't know why we didn't make it void like other string functions
	{
		return ReplaceWord(_Value, StringToReplace, ReplaceTo);
	}

	static string RemovePunctuations(string S1)
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

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}


};
