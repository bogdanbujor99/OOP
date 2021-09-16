#pragma once
#include <iostream>
#include "Car.h"

class Dacia : public Car {
public:
	int SetAverage(Weather w);
	int SetCapacity();
	int SetConsumption();
	void GetName() { std::cout << "Dacia" << std::endl; }
};
