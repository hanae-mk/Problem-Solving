

#include <iostream>
#include <string>
using namespace std;

float ReadNumbers(string Message)
{
	float Number = 0;
	
	cout << Message << endl;
	cin >> Number;

	return Number;
}

float SumNumbers()
{
	int Sum = 0 , Number = 0 , Counter = 1;

	do
	{
	  Number = ReadNumbers("Please enter number " + to_string(Counter)) ;

		if (Number == -99)
		{
			break;
	    }

	  Sum += Number; 
		Counter++;

	} while (Number != -99);

	return Sum ;
}

int main()
{

	cout << endl << "Sum = " << SumNumbers() << endl;

	return 0;

}