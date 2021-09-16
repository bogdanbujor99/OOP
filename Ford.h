#pragma once
#include <iostream>
#include "Car.h"

class Ford : public Car{
public:
	int SetAverage(Weather w);
	int SetCapacity();
	int SetConsumption();
	void GetName() { std::cout << "Ford" << std::endl; }
};