#include "Toyota.h"

void Toyota::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}

void Toyota::SetFuelConsumption(double value)
{
	fuel_consumption = value;
}

void Toyota::AverageRainSpeed(int value)
{
	avg_speed_rain = value;
}

void Toyota::AverageSunnySpeed(int value)
{
	avg_speed_sunny = value;
}

void Toyota::AverageSnowSpeed(int value)
{
	avg_speed_snow = value;
}

int Toyota::Speed(weather weatherType)
{
	if (weatherType == Rain)
		return avg_speed_rain;
	else if (weatherType == Sunny)
		return avg_speed_sunny;
	else
		return avg_speed_snow;
}

void Toyota::BrandName()
{
	cout << "Toyota" << ' ';
}

void Toyota::SetFinishTime(double value)
{
	finishTime = value;
}

double Toyota::FinishTime()
{
	return finishTime;
}

int Toyota::FuelCapacity()
{
	return fuel_capacity;
}

double Toyota::FuelConsumption()
{
	return fuel_consumption;
}