#include <stdio.h>

using namespace std;

int main()
{
	FILE *fis;
	char ch;

	fis = fopen("in.txt", "w+");

	while (1)
	{
		ch = getc(fis);
		printf("%c", ch);
	}

	fclose(fis);

	return 0;
}
