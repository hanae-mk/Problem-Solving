
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"

using namespace std;

int main()
{	

	string S1 = clsInputValidate<string>::ReadString("\nPlease Enter Your String?");
	
	cout << "\nString After Conversion : \n";
	cout << clsUtil<string>::UpperFirstLetterOfEachWord(S1) << endl;
	
	system("pause>0");
	return 0;

}