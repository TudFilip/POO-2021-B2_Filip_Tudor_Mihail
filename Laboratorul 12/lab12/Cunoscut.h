#pragma once
#include "Contact.h"

class Cunoscut : protected Contact {
public:
	char* Cunoscut_PhoneNumber;

	const char* GetType() {
		return "Cunoscut";
	}
};