


#include <iostream>
using namespace std;

string ReadPinCode()
{
	string PinCode;

	cout << "Please enter your PIN Code?" << endl;
	cin >> PinCode;

	return PinCode;

}

bool Login()
{
	string PinCode;
	int Counter = 3;

	do
	{
		Counter--;
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			return 1;
		}

		else
		{
			system("color 4F");
			cout << "\n Wrong Pin , you have " << Counter << " more tries" << endl;
		}

	} while (Counter >= 1 && PinCode != "1234");

	return 0;
}

int main()
{
	if (Login())
	{
		system("color 2F");
		cout << "\n Your account balance is : " << 7500 << endl;
	}
	else
	{
		cout << "\n Your card is blocked call the bank for help \n";
	}

	return 0;

}