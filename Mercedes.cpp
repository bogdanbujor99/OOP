#include "Mercedes.h"

int Mercedes::SetAverage(Weather w) {
	if (w==Weather::Rain) {
		this->average = 80;
	}
	if (w==Weather::Sunny) {
		this->average = 95;
	}
	if (w==Weather::Snow) {
		this->average = 70;
	}
	return average;
}

int Mercedes::SetCapacity() {
	fuelcapacity = 80;
	return fuelcapacity;
}

int Mercedes::SetConsumption() {
	fuelconsumption = 9;
	return fuelconsumption;
}