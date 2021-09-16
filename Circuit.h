#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit{
private:
	Weather w;
	Car* f[10];
	int k = 1;
	int lenght;
public:
	void SetLenght(int x);
	void AddCar(Car* c);
	void SetWeather(Weather w);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};