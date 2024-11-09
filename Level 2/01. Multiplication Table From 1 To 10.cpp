

#include <iostream>
using namespace std;

void PrintTableHeader()
{
	cout << "\n\n\t\t\t Multiplication Table from 1 to 10\n\n" ;
	cout << "\t";

	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n___________________________________________________________________________________________\n";
	cout << "      |" << "\n";
}

string ColumnSeperator(int i)
{
	if (i < 10)
		return "    |";
	else
		return "   |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumnSeperator(i) << " ";

		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}

		cout << endl;

	}
}

int main()
{

	PrintMultiplicationTable();

	return 0;
}