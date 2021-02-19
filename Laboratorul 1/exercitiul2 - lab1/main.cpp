#include <stdio.h>
#include <iostream>

using namespace std;

int in_numar (char ch)
{
    return ch - '0';
}

int main()
{
	FILE *fis;
	char ch;

    int numar = 0, cifra;
    long suma = 0;
	fis = fopen("in.txt", "r");

	while (!feof(fis))
	{

        ch = getc(fis);

		if (ch >= 48 and ch <= 58)
        {
            cifra = in_numar(ch);
            numar = numar*10 + cifra;
        }
        else
        {
            suma = suma + numar;
            numar = 0;
        }

	}

    printf("%d", suma);
	fclose(fis);
	return 0;
}
