#include "Mazda.h"

void Mazda::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}

void Mazda::SetFuelConsumption(double value)
{
	fuel_consumption = value;
}

void Mazda::AverageRainSpeed(int value)
{
	avg_speed_rain = value;
}

void Mazda::AverageSunnySpeed(int value)
{
	avg_speed_sunny = value;
}

void Mazda::AverageSnowSpeed(int value)
{
	avg_speed_snow = value;
}

int Mazda::Speed(weather weatherType)
{
	if (weatherType == Rain)
		return avg_speed_rain;
	else if (weatherType == Sunny)
		return avg_speed_sunny;
	else
		return avg_speed_snow;
}

void Mazda::BrandName()
{
	cout << "Mazda" << ' ';
}

void Mazda::SetFinishTime(double value)
{
	finishTime = value;
}

double Mazda::FinishTime()
{
	return finishTime;
}

int Mazda::FuelCapacity()
{
	return fuel_capacity;
}

double Mazda::FuelConsumption()
{
	return fuel_consumption;
}

Mazda::Mazda(const Mazda& m)
{
	fuel_capacity = m.fuel_capacity;
	fuel_consumption = m.fuel_consumption;
	avg_speed_rain = m.avg_speed_rain;
	avg_speed_snow = m.avg_speed_snow;
	avg_speed_sunny = m.avg_speed_sunny;
	finishTime = m.finishTime;
}