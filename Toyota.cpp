#include "Toyota.h"

int Toyota::SetAverage(Weather w) {
	if (w==Weather::Rain) {
		this->average = 70;
	}
	if (w==Weather::Sunny) {
		this->average = 90;
	}
	if (w==Weather::Snow) {
		this->average = 60;
	}
	return average;
}

int Toyota::SetCapacity() {
	fuelcapacity = 70;
	return fuelcapacity;
}

int Toyota::SetConsumption() {
	fuelconsumption = 8;
	return fuelconsumption;
}