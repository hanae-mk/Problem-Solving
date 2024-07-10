
#include <iostream>
#include "clsInputValidate.h"

using namespace std;

string ReadPinCode()
{
	string PinCode = "";

	PinCode = clsInputValidate<string>::ReadString("\nPlease Enter Your ATM Pin Code? ");

	return PinCode;
}

bool Login()
{
	
	string PinCode = "";
	
	do
	{
		PinCode = ReadPinCode();
		
		if (PinCode == "1234")		
			return true;

		else
		{
			system("Color 4F");
			cout << "\a\nWrong Pin\n";
		}
			
	} while (PinCode != "1234");

}

int main()
{	

	if (Login())
	{
		system("Color 2F");
		cout << "\nYour Balance is : " << 7500 << "\n";
	}

	system("pause>0");
	return 0;

}