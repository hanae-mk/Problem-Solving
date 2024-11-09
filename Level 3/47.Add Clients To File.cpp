

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFileName = "Clients.txt";

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
	
	//Usage of std::ws will extract all the whitespace character

		cout << "\nEnter Account Number?";
		getline(cin >> ws, Client.AccountNumber);

		cout << "\nEnter Pin Code?";
		getline(cin, Client.PinCode);

		cout << "\nEnter Name?";
		getline(cin, Client.Name);

		cout << "\nEnter Phone?";
		getline(cin, Client.Phone);

		cout << "\nEnter Account Balance?";
		cin >> Client.AccountBalance;

		return Client;
	
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
	string ClientRecord = "";

	ClientRecord += Client.AccountNumber + Seperator;
	ClientRecord += Client.PinCode + Seperator;
	ClientRecord += Client.Name + Seperator;
	ClientRecord += Client.Phone + Seperator;
	ClientRecord += to_string(Client.AccountBalance) + Seperator;

	return ClientRecord;

}

void AddDataLineToFile(string FileName, string DataLine)
{
	fstream MyFile;

	MyFile.open(FileName,ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << DataLine << endl;

		MyFile.close();
	}

}

void AddNewClient()
{
	stClient Client;

	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "\nAdding New Client : \n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients?\n\n";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}

int main()
{
	AddClients();

	system("pause>0");

	return 0;

}