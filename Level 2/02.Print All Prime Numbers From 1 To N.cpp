
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"

using namespace std;

enum enNumberType { Prime = 1, NotPrime = 2 };

void PrintPrimeNumbersFrom1ToN(int Number)
{

	cout << "\nPrime Numbers From " << 1 << " To " << Number << " : " << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (clsUtil<int>::CheckNumberType(i) == enNumberType::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	int Number = clsInputValidate<int>::ReadPositiveNumber("\nPlease Enter a Positive Number ?");

	PrintPrimeNumbersFrom1ToN(Number);

	system("pause>0");
	return 0;
}



