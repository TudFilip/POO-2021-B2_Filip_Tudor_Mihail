#include <iostream>
#include <iomanip>

using namespace std;

float operator"" _Kelvin(unsigned long long int value)
{
	return (float)(value - 273.15);
}

float operator"" _Fahrenheit(unsigned long long int value)
{
	return (value - 32) / (float)1.8;
}

int main()
{
	float a = 300_Kelvin;
	cout << "300 de grade Kelvin reprezinta " << setprecision(4) << a << " grade Celsius\n";

	float b = 120_Fahrenheit;
	cout << "120 de grade Fahrenheit reprezinta " << setprecision(4) << b << " grade Celsius\n";
	return 0;
}