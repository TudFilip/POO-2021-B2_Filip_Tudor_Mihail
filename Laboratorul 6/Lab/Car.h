#pragma once
#include <iostream>
#include "Weather.h"

using namespace std;

class Car
{
protected:
	int fuel_capacity;
	double fuel_consumption;
	int avg_speed_rain;
	int avg_speed_sunny;
	int avg_speed_snow;
	double finishTime;
public:
	void virtual SetFuelConsumption(double value) = 0;
	void virtual SetFuelCapacity(int value) = 0;
	void virtual AverageRainSpeed(int value) = 0;
	void virtual AverageSunnySpeed(int value) = 0;
	void virtual AverageSnowSpeed(int value) = 0;
	int virtual Speed(weather weatherType) = 0;
	void virtual BrandName() = 0;
	void virtual SetFinishTime(double value) = 0;
	double virtual FinishTime() = 0;
	int virtual FuelCapacity() = 0;
	double virtual FuelConsumption() = 0;
};
