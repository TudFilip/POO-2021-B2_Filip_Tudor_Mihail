#include "Template_Vector.h"

int main()
{
	Vector<int> v;

	for(int i=0; i<=10; i++)
		v.push(i);

	v.print();

	return 0;
}