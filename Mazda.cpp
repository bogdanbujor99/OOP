#include "Mazda.h"

int Mazda::SetAverage(Weather w) {
	if (w==Weather::Rain) {
		average = 90;
	}
	if (w==Weather::Sunny) {
		average = 100;
	}
	if (w==Weather::Snow) {
		average = 70;
	}
	return average;
}

int Mazda::SetCapacity() {
	fuelcapacity = 80;
	return fuelcapacity;
}

int Mazda::SetConsumption() {
	fuelconsumption = 8;
	return fuelconsumption;
}
