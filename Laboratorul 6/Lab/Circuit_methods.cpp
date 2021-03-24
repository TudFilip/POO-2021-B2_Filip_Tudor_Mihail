#include "Circuit.h"
#include <iomanip>
#include <math.h>

void Circuit::SetLength(double value)
{
	length = value;
}

void Circuit::SetWeather(weather givenWeatherType)
{
	weatherType = givenWeatherType;
}

void Circuit::AddCar(Car* car)
{
	cars[participants++] = car;
}

void Circuit::Race()
{
	double time;
	double max_distance;
	for (int index = 0; index < participants; index++)
	{
		max_distance = cars[index]->FuelCapacity() / cars[index]->FuelConsumption();

		if (max_distance * 100 >= length)
		{
			time = length / (double)cars[index]->Speed(weatherType);
			cars[index]->SetFinishTime(time);
		}
	}
}

void Circuit::ShowFinalRanks()
{
	double time[100];
	int i = 0, j;
	for (int index = 0; index < participants; index++)
	{
		if (cars[index]->FinishTime() != 0)
		{
			time[i] = cars[index]->FinishTime();
			i++;
		}
	}

	int cars_that_finish = i;
	double tmp;
	for (i = 0; i < cars_that_finish - 1; i++)
		for (j = i + 1; j < cars_that_finish; j++)
		{
			if (time[i] > time[j])
			{
				tmp = time[i];
				time[i] = time[j];
				time[j] = tmp;
			}
		}

	cout << "List of time each car needed to finish the circuit:\n";
	for (int index = 0; index < cars_that_finish; index++)
	{
		cout << index + 1 << ".  ";
		if (time[index] < 1.0)
		{
			cout << "0 ore si " << setprecision(3) << time[index] * 60 << " minute\n";
		}
		else
		{
			cout << floor(time[index]) << " ore si ";
			double fr = time[index] - floor(time[index]);
			cout << setprecision(3) << fr * 60 << " minute\n";
		}
	}
	cout << "\n\n";
}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "List of cars that did not finish the circuit:\n";
	for (int index = 0; index < participants; index++)
	{
		if (cars[index]->FinishTime() == 0)
			cars[index]->BrandName();
	}
	cout << "\n\n";
}