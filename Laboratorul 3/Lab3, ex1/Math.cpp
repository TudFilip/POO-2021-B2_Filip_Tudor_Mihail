#include "Math.h"

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int sum = 0, i, prm;
	va_list arg;

	va_start(arg, count);
	
	for(i=0;i<count;i++)
	{
		prm = va_arg(arg, int);
		sum += prm;
	}

	va_end(arg);

	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;
	
	long int number1 = atoi(s1);
	long int number2 = atoi(s2);
	long int number3 = number1 + number2;
	
	char s3[100];
	_itoa_s(number3, s3, 10);
	

	return s3;
}