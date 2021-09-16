#include "Circuit.h"
#include <iostream>

void Circuit::SetLenght(int x) {
	this->lenght = x;
}


void Circuit::AddCar(Car* c) {
	this->f[k] = c;
	f[k]->SetAverage(w);
	f[k]->SetCapacity();
	f[k]->SetConsumption();
	this->k = k + 1;
}

void Circuit::SetWeather(Weather w) {
	this->w = w;
}

void Circuit::Race() {
	int i, j;
	double v[10];
	double vit, t;
	this->k--;
	for (i = 1; i <= this->k; i++) {
		vit =(double)f[i]->SetAverage(w);
		t = this->lenght / vit;
		v[i] = t;
	}

	for (i = 1; i <= this->k - 1; i++) 
		for (j = i + 1; j <= this->k ; j++) {
			if (v[i] > v[j]) {
				std::swap(v[i], v[j]);
				std::swap(this->f[i], this->f[j]);
			}
		}
}

void Circuit::ShowFinalRanks() {
	double vit, t, x, ora, minute;
	for (int i = 1; i <= this->k; i++) {
		std::cout << "Locul " << i << " cu ";
		vit = (double)f[i]->SetAverage(w);
		t = this->lenght / vit;
		x = (int)t * 60;
	     ora = x / 60;
		std::cout << ora<< " ore si ";
		int minute = x - ora * 60;
		std::cout << ora << " minute ";
		f[i]->GetName();
	}
}

void Circuit::ShowWhoDidNotFinish() {
	int i, consumption;
	double x;
	for (i = 1; i <= this->k; i++) {
		x =(double) f[i]->SetCapacity();
		consumption= (int)f[i]->SetConsumption();
		x = x * 100;
		x = x / consumption;
		if (x <this->lenght) {
			std::cout << "Nu termina cursa ";
			f[i]->GetName();
		}
	}
}