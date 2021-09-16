#pragma once
#include <iostream>
#include "Car.h"

class Mercedes : public Car {
public:
	int SetAverage(Weather w);
	int SetCapacity();
	int SetConsumption();
	void GetName() { std::cout << "Mercedes" << std::endl; }
};