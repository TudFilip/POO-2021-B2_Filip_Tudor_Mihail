#include "Number.h"

Number::Number(const char* nr_value, int nr_base)
{
	value = new char[strlen(nr_value)];
	memcpy(value, nr_value,strlen(nr_value) + 1);
	base = nr_base;
}
/*
Number::~Number()
{
	delete value;
	value = nullptr;
	base = 0;
}
*/

Number::Number(const Number& nr)
{
	memcpy(value, nr.value, strlen(nr.value) + 1);
	base = nr.base;
}

Number::Number(Number&& nr)
{
	value = nr.value;
	nr.value = nullptr;
	base = nr.base;
	nr.base = 0;
}

/*int operator+(const Number& nr1, const Number& nr2)
{

}*/

void Number::SwitchBase(int newBase)
{
	int x=0;
	if (base != 10) {
		int digit;
		int power = 1;
		for (int i = 0; i < strlen(value); i++) 
		{
			if (value[i] >= 'A') 
				digit = 10 + int(value[i]) - 65;
			else
				digit = int(value[i]) - 48;
			x = x + digit * power;
			power *= base;
		}
		base = 10;
	}
	char *rest = new char[100];
	if (newBase != 10) 
	{
		for (int i = 0; i < strlen(value); i++)
		{
			int r = x % newBase;
			x /= newBase;
			if (r >= 10)
				rest[i] = 65 + (r - 10);
			else
				rest[i] = 48 + r;
		}
	}

	if (newBase == 10) {
		memcpy(value, rest, strlen(rest) + 1);
	}
	else
	{
		char tmp[100];
		for (int i = 0; i < strlen(value); i++)
			tmp[i] = rest[strlen(value) - i - 1];
		memcpy(value, tmp, strlen(value) + 1);
	}
	base = newBase;
}

void Number::Print()
{
	cout << "The number value is: " << value << '\n';
	cout << "The current base of the number is: " << base << "\n\n";
}

int Number::GetDigitsCount()
{
	return strlen(value);
}

int Number::GetBase()
{
	return this->base;
}
