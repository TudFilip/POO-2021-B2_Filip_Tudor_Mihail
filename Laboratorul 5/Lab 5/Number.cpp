#include "Number.h"

Number::Number(const char* nr_value, int nr_base)
{
	value = new char[strlen(nr_value) + 1];
	memcpy(&value, nr_value, strlen(nr_value) + 1);
	base = nr_base;
}

Number::~Number()
{
	delete value;
	value = nullptr;
	base = 0;
}

Number::Number(const Number& nr)
{
	value = new char[strlen(nr.value) + 1];
	memcpy(&value, nr.value, strlen(nr.value) + 1);
	base = nr.base;
}

Number::Number(Number&& nr)
{
	value = nr.value;
	nr.value = nullptr;
	base = nr.base;
	nr.base = 0;
}



void Number::SwitchBase(int newBase)
{
	if (newBase != base)
	{
		int digit;
		int newValue;
		if (base != 10)
		{
			newValue = 0;
			int power = GetDigitsCount() - 1;
			for (int cf = 0; cf < GetDigitsCount(); cf++)
			{
				if (value[cf] >= '0' && value[cf] <= '9')
					digit = value[cf] - '0';
				else
					if (value[cf] == 'A')
						digit = 10;
					else
						if (value[cf] == 'B')
							digit = 11;
						else
							if (value[cf] == 'C')
								digit = 12;
							else
								if (value[cf] == 'D')
									digit = 13;
								else
									if (value[cf] == 'E')
										digit = 14;
									else
										if (value[cf] == 'F')
											digit = 15;
				newValue += digit * (int)pow(base, power);
				power--;
			}
		}

		if (newBase != 10)
		{
			int tmpValue;
			if (base != 10)
				tmpValue = newValue;
			else
				tmpValue = atoi(value);
			newValue = 0;
			int p = 1;
			while (tmpValue != 0)
			{
				if ((tmpValue % newBase) > 0 && (tmpValue % newBase) <= 9)
					digit = tmpValue % newBase;
				else
					if ((tmpValue % newBase))
						newValue = newValue + (tmpValue % newBase) * p;
				p *= 10;
			}
		}

	}
	base = newBase;

}

void Number::Print()
{
	cout << "The number value is: " << value << "\n";
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
