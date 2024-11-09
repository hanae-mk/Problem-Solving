
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


string TrimLeft(string S1)
{
	
	for (int i = 0; i < S1.length(); i++)  
	{
		if (S1[i] != ' ') //true : that means there is a character
		{
			return S1.substr(i, S1.length() - i); //returns all the string
			     //Prints all x letters from position i
				 
			//If the first element is a character the trimleft is then failed

		}
	}

	return "";
}

string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
			

		}
	}

	return "";
}

string Trim(string S1)
{
	return (TrimLeft(TrimRight(S1)));

}

int main()
{
	string S1 = "  Hanae   ";

	cout  << "\nString     = " << S1;

	cout << "\n\nTrim Left  = " << TrimLeft(S1);
	cout << "\nTrim Right =" << TrimRight(S1);
	cout << "\nTrim       = " << Trim(S1);

	//The trim function is used to remove all leading or trailing white spaces from the string.

	system("pause>0");

}



