#include "Mercedes.h"

void Mercedes::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}

void Mercedes::SetFuelConsumption(double value)
{
	fuel_consumption = value;
}

void Mercedes::AverageRainSpeed(int value)
{
	avg_speed_rain = value;
}

void Mercedes::AverageSunnySpeed(int value)
{
	avg_speed_sunny = value;
}

void Mercedes::AverageSnowSpeed(int value)
{
	avg_speed_snow = value;
}

int Mercedes::Speed(weather weatherType)
{
	if (weatherType == Rain)
		return avg_speed_rain;
	else if (weatherType == Sunny)
		return avg_speed_sunny;
	else
		return avg_speed_snow;
}

void Mercedes::BrandName()
{
	cout << "Mercedes" << ' ';
}

void Mercedes::SetFinishTime(double value)
{
	finishTime = value;
}

double Mercedes::FinishTime()
{
	return finishTime;
}

int Mercedes::FuelCapacity()
{
	return fuel_capacity;
}

double Mercedes::FuelConsumption()
{
	return fuel_consumption;
}