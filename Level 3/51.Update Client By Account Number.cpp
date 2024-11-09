
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "UpdateClientsFile.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;

};

string ReadClientAccountNumber()
{
	string AccNum = "";

	cout << "\nPlease enter your account number ?\n";
	cin >> AccNum;

	return AccNum;
}

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

vector <stClient> LoadClientDataFromFile(string FileName)
{
	vector <stClient> vClient;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	string Line = "";
	stClient Client;

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClient.push_back(Client);
		}

		MyFile.close();
	}

	return vClient;

}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClient, stClient& Client)
{

	for (stClient& C : vClient)
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
	cout << left << setw(17) << "\nAccount Number" << setw(3) << " : " << Client.AccountNumber;
	cout << setw(17) << "\nPin Code" << setw(3) << " : " << Client.PinCode;
	cout << setw(17) << "\nName" << setw(3) << " : " << Client.Name;
	cout << setw(17) << "\nPhone" << setw(3) << " : " << Client.Phone;
	cout << setw(17) << "\nAccount Balance" << setw(3) << " : " << Client.AccountBalance;

}

stClient UpdateClientRecord(string AccountNumber)
{
	stClient Client;

	Client.AccountNumber = AccountNumber; //Primal Key

	cout << "\nEnter Pin Code?";
	getline(cin >> ws, Client.PinCode);

	cout << "\nEnter Name?";
	getline(cin , Client.Name);

	cout << "\nEnter Phone?";
	getline(cin , Client.Phone);

	cout << "\nEnter Account Balance?";
	cin >> Client.AccountBalance;

	return Client;

}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
	string ClientData = "";

	ClientData += Client.AccountNumber + Seperator;
	ClientData += Client.PinCode + Seperator;
	ClientData += Client.Name + Seperator;
	ClientData += Client.Phone + Seperator;
	ClientData += to_string(Client.AccountBalance);

	return ClientData;

}

vector <stClient> SaveClientDataToFile(string FileName, vector <stClient> vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string DataLine = "";

	if (MyFile.is_open())
	{
		for (stClient& C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		
		MyFile.close();
	}

	return vClient;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
	char Answer = 'n';
	stClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
	{
		PrintClientCard(Client);

		cout << "\nAre you sure you want update this client ? Y/N?";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			for (stClient& C : vClient)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = UpdateClientRecord(AccountNumber);
					break;
				}
			}

			SaveClientDataToFile(ClientsFileName, vClient);

			cout << "\nClient Updated Successfully\n";
			return true;

		}
	}

	cout << "\nClient with account number (" << AccountNumber << ") is not found!\n";

	return false;
}

int main()
{
	string AccountNumber = ReadClientAccountNumber();
	
	vector <stClient> vClient = LoadClientDataFromFile(ClientsFileName);

	

	UpdateClientByAccountNumber(AccountNumber, vClient);


}
