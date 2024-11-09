
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "MyClients.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

string ReadClientAccountNumber()
{
	string AccNum = "";

	cout << "\nPlease Enter Account Number ?";
	cin >> AccNum;

	return AccNum;
}

vector <string> SplitString(string Line, string Delim)
{
	vector <string> vString;

	string Token = "";
	short pos = 0;

	while ((pos = Line.find(Delim)) != std::string::npos)
	{
		Token = Line.substr(0, pos);

		if (Token != "")
		{
			vString.push_back(Token);
		}

		Line = Line.erase(0, pos + Delim.length());
	}

	if (Line != "")
	{
		vString.push_back(Line);
	}

	return vString;

}

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{

	vector <string> vClientData;

	vClientData = SplitString(Line, Seperator);
	stClient Client;

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

vector <stClient> LoadClientDataFromFile(string ClientsFileName)
{
	fstream MyFile;
	vector <stClient> vClient;

	MyFile.open(ClientsFileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClient.push_back(Client);
		}

		MyFile.close();
	}

	return vClient;
}

bool FindClientByAccountNumber(stClient &Client, string AccountNumber)
{
	vector <stClient> vClient = LoadClientDataFromFile(ClientsFileName);

	for (stClient C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}

	return false;
}

void PrintClientCard(stClient Client)
{
	cout << "\nThe following are the client details : \n";

	cout << "\n" << left << setw(17) << "Account Number " << setw(3) << " : " << Client.AccountNumber;
	cout << "\n" << setw(17)<< "Pin Code " << setw(3) << " : " << Client.PinCode;
	cout << "\n" << setw(17) << "Name " << setw(3) << " : " << Client.Name;
	cout << "\n" << setw(17) << "Phone " << setw(3) << " : " << Client.Phone;
	cout << "\n" << setw(17) << "Account Balance " << setw(3) << " : " << Client.AccountBalance;

}

int main()
{
	
	stClient Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(Client, AccountNumber))
	{
		PrintClientCard(Client);
	}
	else
	{	
		cout << "\nClient with account number (" << AccountNumber << ") Not Found!";
	}

	system("pause>0");
	return 0;

}