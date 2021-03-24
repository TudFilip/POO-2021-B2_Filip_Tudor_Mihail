#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Number
{
	unsigned int base;
	char* value;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	//~Number();
	Number(const Number& nr);
	Number(Number&& nr);
	Number& operator=(const Number& nr);
	friend int operator+(const Number& nr1, const Number& nr2);
	friend int operator+=(const Number& nr1, const Number& nr2);
	friend int operator-(const Number& nr1, const Number& nr2);
	friend int operator-=(const Number& nr1, const Number& nr2);
	int operator!();
	Number& operator--();
	Number operator--(int value);

	// add operators and copy/move constructor
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};