#include "sort_template.h"


int main()
{
	Sort<int> obj(6, -10, -4, -2, -6, -3, -1);

	obj.Sorting();
	obj.Print();

	system("pause");
	return 0;
}