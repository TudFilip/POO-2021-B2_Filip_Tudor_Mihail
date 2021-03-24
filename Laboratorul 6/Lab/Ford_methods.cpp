#include "Ford.h"

void Ford::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}

void Ford::SetFuelConsumption(double value)
{
	fuel_consumption = value;
}

void Ford::AverageRainSpeed(int value)
{
	avg_speed_rain = value;
}

void Ford::AverageSunnySpeed(int value)
{
	avg_speed_sunny = value;
}

void Ford::AverageSnowSpeed(int value)
{
	avg_speed_snow = value;
}

int Ford::Speed(weather weatherType)
{
	if (weatherType == Rain)
		return avg_speed_rain;
	else if (weatherType == Sunny)
		return avg_speed_sunny;
	else
		return avg_speed_snow;
}

void Ford::BrandName()
{
	cout << "Ford" << ' ';
}

void Ford::SetFinishTime(double value)
{
	finishTime = value;
}

double Ford::FinishTime()
{
	return finishTime;
}

int Ford::FuelCapacity()
{
	return fuel_capacity;
}

double Ford::FuelConsumption()
{
	return fuel_consumption;
}