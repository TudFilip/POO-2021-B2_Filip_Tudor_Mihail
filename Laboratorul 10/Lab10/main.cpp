#include "array_header.h"

int main()
{
	Array<int> a1;

	//0   1   2   4
	//10  20  30 

	a1 += 10;
	a1 += 20;
	a1 += 30;
	a1 += 30;
	a1 += 30;
	a1 += 30;

	cout << a1[0];
	cout << a1[1];
	cout << '\n' << a1.GetCapacity();


	a1.Delete(0);
	//cout << a1[0];


	system("pause");
	return 0;
}

