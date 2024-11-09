


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

short CountEachWordInString(string S1)
{
	string delim = " "; //delimiter huwa lfassel aw lfaragh 
	short position = 0;
	string sword; //Define a string variable
	short Counter = 0;

	//We use find() function to get the position of the delimiters
	while ((position = S1.find(delim)) != std::string::npos)
	{
		sword = S1.substr(0, position); //Store the word (substring)

		if (sword != " ")
		{
			Counter++;
		}

		S1.erase(0, position + delim.length());//Erase until position and move to next word
	}

	if (S1 != "")
	{
		Counter++; //Counts the last word in string
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nThe number of words in your string is : " << CountEachWordInString(S1) << endl;

	system("pause>0");

}