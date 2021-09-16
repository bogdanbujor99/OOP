#include "Ford.h"

int Ford::SetAverage(Weather w) {
	if (w==Weather::Rain) {
		this->average = 60;
	}
	if (w==Weather::Sunny) {
		this->average = 80;
	}
	if (w==Weather::Snow) {
		this->average = 50;
	}
	return average;
}

int Ford::SetCapacity() {
	fuelcapacity = 60;
	return fuelcapacity;
}

int Ford::SetConsumption() {
	fuelconsumption = 7;
	return fuelconsumption;
}