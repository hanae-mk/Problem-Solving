

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
	vector <string> vDate;
	stDate Date;

	vDate = SplitString(DateString, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ReplaceWordInString(string DateString, string StringToReplace, string ReplaceTo)
{
	short pos = DateString.find(StringToReplace);

	while ((pos != std::string::npos))
	{
		DateString = DateString.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = DateString.find(StringToReplace);//Find Next
	}

	return DateString;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";

	FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;
}

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

	stDate Date = StringToDate(DateString);

	cout << "\n" << FormateDate(Date) << endl;
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << endl;
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << endl;
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << endl;
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << endl;
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;
	
	system("pause>0");
	return 0;


}