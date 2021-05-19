#pragma once
#include <iostream>

using namespace std;

class Contact {
protected:
	char* Nume;
	virtual const char* GetType() = 0;
};