
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "DeleteClientsFile.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false; //flag

};

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	string Token = "";
	short pos = 0;

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

stClient ConvertLineToRecord(string Line , string Seperator = "#//#")
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

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
	string ClientRecord = "";

	ClientRecord += Client.AccountNumber + Seperator;
	ClientRecord += Client.PinCode + Seperator;
	ClientRecord += Client.Name + Seperator;
	ClientRecord += Client.Phone + Seperator;
	ClientRecord += to_string(Client.AccountBalance);

	return ClientRecord;

}

vector <stClient> LoadClientDataFromFile(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	vector <stClient> vClient;

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

void PrintClientCard(stClient Client)
{
	cout << "\nThe following are the clients details : \n";
	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;

}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClient, stClient& Client)
{
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
	for (stClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

vector <stClient> SaveClientDataToFile(string FileName, vector <stClient> vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //OverWrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				//We Only write records that are not marked for delete
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}

	return vClient;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
	stClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
	{
		PrintClientCard(Client);

		cout << "\nAre you sure you want delete this client? Y/N?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
			SaveClientDataToFile(ClientsFileName, vClient);

			//Refresh Clients
			vClient = LoadClientDataFromFile(ClientsFileName);

			cout << "\nClient Deleted Successfully.";

			return true;
		}
	}

	else
	{
		cout << "\nClient With Account Number (" << AccountNumber << ") is Not Found!\n";

		return false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nPlease enter Account Number ?";
	cin >> AccountNumber;

	return AccountNumber;
}

int main()
{
	vector <stClient> vClients = LoadClientDataFromFile(ClientsFileName);

	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);

	system("pause>0");
	return 0;

}
