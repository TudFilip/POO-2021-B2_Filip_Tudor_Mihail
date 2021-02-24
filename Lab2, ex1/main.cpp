#include "NumberList.h"

int main()
{
	NumberList lista1, lista2;

	lista1.Init();
	lista2.Init();

	int x1, y1, z1;
	cin >> x1 >> y1 >> z1;

	lista1.Add(x1);
	lista1.Add(y1);
	lista1.Add(z1);



	return 0;
}