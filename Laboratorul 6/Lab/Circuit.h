#pragma once
#include <iostream>
#include "Car.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"

using namespace std;

class Circuit
{
private:
	double length;
	int participants = 0;
	Car* cars[100];
	weather weatherType;

public:
	void SetLength(double value);
	void SetWeather(weather givenWeatherType);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};
