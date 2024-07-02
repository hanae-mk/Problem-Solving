
#include <iostream>
#include "clsInputValidate.h"

using namespace std;

template <class T>

string ReadName()
{
	cout << "\nPlease Enter Your Name? ";
	return clsInputValidate<string>::ReadString();
}

void PrintName(string Name)
{
	cout << "\nYour Name is : " << Name << endl;
}

int main()
{
	string Name = ReadName<string>();

	PrintName(Name);

	system("pause>0");
	return 0;
}