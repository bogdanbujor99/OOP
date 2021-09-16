#pragma once
#include "Weather.h"

class Car {
protected:
	int fuelcapacity;
	int fuelconsumption;
	int average;
public:
	virtual int SetAverage(Weather w)=0;
	virtual int SetCapacity()=0;
	virtual int SetConsumption()=0;
	virtual void GetName() = 0;
};