#include "Sort.h"

int main()
{
	Sort list1(20, 5, 15);
	list1.InsertSort(true);
	list1.Print();
	list1.BubbleSort(false);
	list1.Print();

	cout << "\n---------------------------\n";

	int v[5] = { 1,2,3,4,5 };
	Sort list2(v, 5);
	list2.InsertSort(true);
	list2.Print();
	list2.BubbleSort(false);
	list2.Print();

	cout << "\n---------------------------\n";

	Sort list3(10, 3, 4, 6, 12, 90, 32, 1, 2, 9, 8);
	list3.InsertSort(true);
	list3.Print();
	list3.BubbleSort(false);
	list3.Print();
	
	cout << "\n---------------------------\n";

	char str[] = "12,10,9,20,15,6,7,1";
	Sort list4(str);
	list4.InsertSort(true);
	list4.Print();
	list4.BubbleSort(false);
	list4.Print();

	return 0;
}