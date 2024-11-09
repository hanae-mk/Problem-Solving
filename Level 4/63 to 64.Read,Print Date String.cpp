

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

string ReadStringDate(string Message)
{
	string DateString;

	cout << Message;
	getline(cin >> ws, DateString);

	return DateString;
}

vector <string> SplitString(string Line, string Delim)
{
	short pos = 0;
	string word = "";

	vector <string> vString;

	while ((pos = Line.find(Delim)) != std::string::npos)
	{
		word = Line.substr(0, pos);

		if (word != "")
		{
			vString.push_back(word);
		}

		Line.erase(0, pos + Delim.length());
	}

	if (Line != "")
	{
		vString.push_back(Line);
	}

	return vString;
}

stDate StringToDate(string DateString)
{
	stDate Date;
	vector <string> vDate;

	vDate = SplitString(DateString, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;

}

string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);	
}

int main()
{
	string DateString = ReadStringDate("\nPlease enter date dd/mm/yyyy ?");

	stDate Date = StringToDate(DateString);

	cout << "\nDay   :" << Date.Day;
	cout << "\nMonth :" << Date.Month;
	cout << "\nYear  :" << Date.Year;

	cout << "\nYou Entered :" << DateToString(Date);

	system("pause>0");
	return 0;

}