

#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Message)
{
	float Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;

}

enOperationType ReadOperationType()
{
	char OT = '+';

	cout << "Please enter Operation Type ( + , - , * , / )?\n";
	cin >> OT;

	return (enOperationType)OT;

}

float Calculate(float Number1, float Number2 , enOperationType OperationType)
{

	switch (OperationType)
	{
	case enOperationType::Add:
		return Number1 + Number2;

	case enOperationType::Subtract:
		return Number1 - Number2;

	case enOperationType::Multiply:
		return Number1 * Number2;

	case enOperationType::Divide:
		return Number1 / Number2;

	default:
		cout << "Wrong Opertion";

	}
}

int main()
{
	float Number1 = ReadNumber("Please enter first number?");
	float Number2 = ReadNumber("Please enter second number?");

	enOperationType OpType = ReadOperationType();

	cout << endl << "Result = " << Calculate(Number1, Number2, OpType) << endl;

	return 0;
	

}