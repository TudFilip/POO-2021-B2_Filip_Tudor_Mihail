#pragma once
#include "Car.h"

class Mazda : public Car
{
protected:
	void virtual SetFuelConsumption(double value) override;
	void virtual SetFuelCapacity(int value) override;
	void virtual AverageRainSpeed(int value) override;
	void virtual AverageSunnySpeed(int value) override;
	void virtual AverageSnowSpeed(int value) override;
	int Speed(weather weatherType) override;
	void BrandName() override;
	void SetFinishTime(double value) override;
	double FinishTime() override;
	int FuelCapacity() override;
	double FuelConsumption() override;

	int fuel_capacity;
	double fuel_consumption;
	int avg_speed_rain;
	int avg_speed_sunny;
	int avg_speed_snow;
	double finishTime;

public:
	Mazda() {
		finishTime = 0.0;
		SetFuelConsumption(12);
		SetFuelCapacity(55);
		AverageRainSpeed(110);
		AverageSunnySpeed(140);
		AverageSnowSpeed(100);
	}
};
