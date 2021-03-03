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
	int sum = 0, i = 0, prm;
	va_list arg;

	va_start(arg, count);
	while (i < count)
	{
		prm = va_arg(arg, int);
		sum += prm;
		i++;
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
	
	char* s3;
	itoa(number3, s3, 10);
	
	return s3;
}