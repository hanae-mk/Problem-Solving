
#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = " ";

	cout << "Please enter your string ?\n";
	getline(cin, S1);

	return S1;
}

short CountCapitalLettersInString(string S1)
{
	short Counter = 0;
	
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

short CountSmallLettersInString(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	string S1 =  ReadString() ;

	cout << "\nString Length = ";
	cout << S1.length();

	cout << "\nCapital Letters Count = ";
	cout << CountCapitalLettersInString(S1);

	cout << "\nSmall Letters Count = ";
	cout << CountSmallLettersInString(S1);

	cout << endl;



}