
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clientssss.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string ClientName = "";
	string Phone = "";
	double AccountBalance = 0;

};

vector <string> SplitString(string S1, string Delim = "#//#")
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

		S1 = S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;

}

stClient ConvertLineToRecord(string Line)
{
	vector <string> vClientData;

	vClientData = SplitString(Line);
	stClient Client;

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.ClientName = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;

}

vector <stClient> LoadClientDataFromFileToVector(string ClientFileName)
{
	vector <stClient> vClient;
	
	fstream MyFile;
	MyFile.open(ClientFileName, ios::in);

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

void PrintClientRecord(stClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.ClientName;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintAllClientsData(vector <stClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n____________________________________________";
	cout << "______________________________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Account Balance";

	cout << "\n____________________________________________";
	cout << "______________________________________________________________\n" << endl;

	for (stClient& Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
}

int main()
{
	vector <stClient> vClients = LoadClientDataFromFileToVector(ClientsFileName);
	PrintAllClientsData(vClients);

	system("pause>0");

}