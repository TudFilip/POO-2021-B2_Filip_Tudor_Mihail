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

	int x2, y2, z2;
	cin >> x2 >> y2 >> z2;

	lista2.Add(x2);
	lista2.Add(y2);
	lista2.Add(z2);

	lista2.Sort();

	lista1.Print();
	lista2.Print();

	return 0;
}