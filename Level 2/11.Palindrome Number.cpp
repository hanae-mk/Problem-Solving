
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{ 

	cout << Message << endl;
	cin >> Number;

	} while (Number <= 0);

	return Number;
}

int ReverseNumber(int Number)
{
	int Remainder = 0, Number2 = 0;
	
	while (Number > 0)
	{  

	Remainder = Number % 10; 
	Number = Number / 10; 
	Number2 = Number2 * 10 + Remainder;
     
	}
	return Number2;

}

/*void Check*/bool IsPalindromeNumber(int Number)
{
	/*if (ReverseNumber(Number) == Number)
		cout << "Yes, it is a palindrome number" << endl;
	else
		cout << "No, it is NOT a palindrome number" << endl;*/

	return Number == ReverseNumber(Number);
}
	

int main()
{
	/*int Number = ReadPositiveNumber("Please enter a positive number ? ");
	
	CheckPalindrome(Number);*/

	if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number ? ")))
		cout << "Yes, it is a palindrome number" << endl;
	else
		cout << "No, it is NOT a palindrome number" << endl; 


	return 0;
}