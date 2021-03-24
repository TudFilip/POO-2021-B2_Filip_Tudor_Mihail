#pragma once
#include "Car.h"

class Ford : public Car
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
	Ford() {
		finishTime = 0.0;
		SetFuelConsumption(11);
		SetFuelCapacity(60);
		AverageRainSpeed(100);
		AverageSunnySpeed(130);
		AverageSnowSpeed(90);
	}
	Ford(const Ford& f);
};
