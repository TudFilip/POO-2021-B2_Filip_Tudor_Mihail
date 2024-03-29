#include "Dacia.h"

void Dacia::SetFuelCapacity(int value)
{
	fuel_capacity = value;
}

void Dacia::SetFuelConsumption(double value)
{
	fuel_consumption = value;
}

void Dacia::AverageRainSpeed(int value)
{
	avg_speed_rain = value;
}

void Dacia::AverageSunnySpeed(int value)
{
	avg_speed_sunny = value;
}

void Dacia::AverageSnowSpeed(int value)
{
	avg_speed_snow = value;
}

int Dacia::Speed(weather weatherType)
{
	if (weatherType == Rain)
		return (int)avg_speed_rain;
	else if (weatherType == Sunny)
		return (int)avg_speed_sunny;
	else
		return (int)avg_speed_snow;
}

void Dacia::BrandName()
{
	cout << "Dacia" << ' ';
}

void Dacia::SetFinishTime(double value)
{
	finishTime = value;
}

double Dacia::FinishTime()
{
	return finishTime;
}

int Dacia::FuelCapacity()
{
	return fuel_capacity;
}

double Dacia::FuelConsumption()
{
	return fuel_consumption;
}

Dacia::Dacia(const Dacia& d)
{
	fuel_capacity = d.fuel_capacity;
	fuel_consumption = d.fuel_consumption;
	avg_speed_rain = d.avg_speed_rain;
	avg_speed_snow = d.avg_speed_snow;
	avg_speed_sunny = d.avg_speed_sunny;
	finishTime = d.finishTime;
}