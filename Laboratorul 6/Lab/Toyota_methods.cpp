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

Toyota::Toyota(const Toyota& t)
{
	fuel_capacity = t.fuel_capacity;
	fuel_consumption = t.fuel_consumption;
	avg_speed_rain = t.avg_speed_rain;
	avg_speed_snow = t.avg_speed_snow;
	avg_speed_sunny = t.avg_speed_sunny;
	finishTime = t.finishTime;
}