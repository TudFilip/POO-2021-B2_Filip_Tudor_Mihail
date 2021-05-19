#pragma once
#include "Contact.h"

class Prieten : protected Contact {
public:
	struct Adress {
		char* postalCode;
		char* street;
		char* city;
	};
	struct BirthDate {
		int year;
		int month;
		int day;
	};
	BirthDate Prieten_DateOfBirth;
	Adress Prieten_Adress;
	char* Prieten_PhoneNumber;
};