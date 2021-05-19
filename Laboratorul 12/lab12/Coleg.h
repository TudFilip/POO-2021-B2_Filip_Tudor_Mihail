#pragma once
#include "Contact.h"

class Coleg : protected Contact {
public:
	struct Adress {
		char* postalCode;
		char* street;
		char* city;
	};
	Adress Coleg_Adress;
	char* Coleg_PhoneNumber;
	char* Coleg_FirmName;

	const char* GetType() {
		return "Coleg";
	}
};