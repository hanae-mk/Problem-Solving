

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

void PrintEachWordInString(string S1)
{
	
	cout << "\nYour String Words are : \n\n";

	string delim = " "; //delimiter huwa lfassel aw lfaragh 
	short position = 0;
	string sword; //Define a string variable

	//We use find() function to get the position of the delimiters
	while ((position = S1.find(delim)) != std::string::npos)
	{
		sword = S1.substr(0, position); //Store the word

		if (sword != "")
		{
			cout << sword << endl;
		}

		S1.erase(0, position + delim.length());//Erase until position and move to next word
	}

	if (S1 != "")
	{
		cout << S1 << endl;
	}
}

int main()
{
	
	PrintEachWordInString(ReadString());

	system("pause>0");
}