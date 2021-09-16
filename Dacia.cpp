#include "Dacia.h"

int Dacia::SetAverage(Weather w) {
	if (w==Weather::Rain) {
		this->average = 50;
	}
	if (w==Weather::Sunny) {
		this->average = 60;
	}
	if (w==Weather::Snow) {
		this->average = 40;
	}
	return average;
}

int Dacia::SetCapacity() {
	fuelcapacity = 50;
	return fuelcapacity;
}

int Dacia::SetConsumption() {
	fuelconsumption = 6;
	return fuelconsumption;
}