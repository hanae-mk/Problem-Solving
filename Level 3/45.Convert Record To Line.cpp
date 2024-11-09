
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

stClient ReadNewClient()
{
	stClient Client;

	cout << "\nEnter Account Number?";
	getline(cin, Client.AccountNumber);

	cout << "\nEnter PinCode?";
	getline(cin, Client.PinCode);

	cout << "\nEnter Name?";
	getline(cin, Client.Name);

	cout << "\nEnter Phone?";
	getline(cin, Client.Phone);

	cout << "\nEnter Account Balance?";
	cin >> Client.AccountBalance;

	return Client;

}

string ConvertRecordToLine(stClient Client, string Seperator)
{
	string ClientRecord = "";

	ClientRecord = Client.AccountNumber + Seperator;
	ClientRecord += Client.PinCode + Seperator;
	ClientRecord += Client.Name + Seperator;
	ClientRecord += Client.Phone + Seperator;
	ClientRecord += to_string(Client.AccountBalance);

	return ClientRecord;
}

int main()
{

	cout << "\nPlease Enter Client Data :\n";

	stClient Client;
	Client = ReadNewClient();

	cout << "\n\nClient Record For Saving is : \n";
	cout << ConvertRecordToLine(Client, "#//#");

	system("pause>0");
}
