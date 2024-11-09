
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	short pos = 0;
	string Token;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		Token = S1.substr(0, pos);

		if (Token != "")
		{
			vString.push_back(Token);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	stClient Client;
	vector <string> vClientData;

	vClientData = SplitString(Line, Seperator); //Cut String

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); //cast string to double

	return Client;

}

void PrintClientRecord(stClient Client)
{
	
	cout << left << setw(18) << "\nAccount Number " << setw(3) << ":" << Client.AccountNumber;
	cout << setw(18) << "\nPin Code " << setw(3) << ":" << Client.PinCode;
	cout << setw(18) << "\nName " << setw(3) << ":" << Client.Name;
	cout << setw(18) << "\nPhone " << setw(3) << ":" << Client.Phone;
	cout << setw(18) << "\nAccountBalance " << setw(3) << ":" << Client.AccountBalance;

}

int main()
{
	string Line = "A150#//#1234#//#Hanae Messari Khali#//#0702987#//#5250.000000";
	cout << "\nLine Record is : \n";
	cout << Line;

	cout << "\n\nThe Following is the extracted client Record : \n";

	stClient Client;
	Client = ConvertLineToRecord(Line);

	PrintClientRecord(Client);

	system("pause>0");

}