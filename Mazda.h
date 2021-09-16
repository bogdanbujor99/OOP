#pragma once
#include <iostream>
#include "Car.h"

class Mazda : public Car {
public:
    int SetAverage (Weather w);
	int SetCapacity();
	int SetConsumption();
	void GetName() { std::cout << "Mazda" << std::endl; }
};