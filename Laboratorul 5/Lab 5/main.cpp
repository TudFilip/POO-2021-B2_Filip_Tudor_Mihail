#include "Number.h"

int main()
{
	Number n("255", 10);
	n.Print();
	n.SwitchBase(2);
	n.Print();
	return 0;
}