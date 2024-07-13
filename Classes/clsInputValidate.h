#pragma once

#include <iostream>
#include "clsDate.h"

template <class T>

class clsInputValidate
{
public:

	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>= From && Date <= To 
		//26/4>= 1/1  && 26/4 <= 31/12

		if (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&& clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			return true;

		//Date >= To && Date <= From  
		//26/4 >= 1/1 && 26/4 <= 31/12

		if (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			&& clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			return true;

		return false;

	}

	static T ReadNumber(string Message, string ErrorMessage = "Invalid Number, Enter Again : ")
	{
		T Number = 0;

		cout << Message;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}

	static T ReadPositiveNumber(string Message, string ErrorMessage = "Invalid Number, Enter a Positive Number : ")
	{
		
		T Number = ReadNumber(Message);

		while (Number <= 0)
		{
			cout << ErrorMessage;
			Number = ReadNumber(Message);
		}

		return Number;
	}

	static T ReadNumberBetween(string Message, T From, T To, string ErrorMessage = "Number is not within range, Enter Again :\n")
	{
		T Number = ReadNumber(Message);

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber(Message);
		}

		return Number;

	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}


};


