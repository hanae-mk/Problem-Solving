
#include <iostream>
#include "clsUtil.h"

using namespace std;

int main()
{
	clsUtil<int>::Srand();
	
	int arr[3][3];

	clsUtil<int>::FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\nThe following is a 3*3 random matrix : \n";

	clsUtil<int>::PrintMatrix(arr, 3, 3);

	system("pause>0");
	return 0;

}