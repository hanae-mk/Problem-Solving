
#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = " ";

	cout << "Please enter your String ?\n";
	getline(cin, S1);

	return S1;
}

void PrintFirstLetterOfEachWord(string S1)
{
	//String is an array

	bool IsFirstLetter = true;

	cout << "\nFirst Letters Of This String : \n";

	for (short i = 0; i < S1.length(); i++)
	{
		//Debuged
		if (S1[i] != ' ' && IsFirstLetter) //true  false false false false false
		{                                  //  h     a     n     a     e     " "
			cout << S1[i] << endl;
		}

		IsFirstLetter = (S1[i] == ' ' ? true : false); //false false false false false true

	}
}

int main()
{
	PrintFirstLetterOfEachWord(ReadString());

	system("pause>0");

}