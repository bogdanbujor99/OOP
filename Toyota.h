#pragma once
#include <iostream>
#include "Car.h"

class Toyota : public Car {
public:
	int SetAverage(Weather w);
	int SetCapacity();
	int SetConsumption();
	void GetName() { std::cout << "Toyota" << std::endl; }
};