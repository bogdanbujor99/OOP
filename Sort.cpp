#include<iostream>
#include <cstdarg>
#include<string.h>
#include <initializer_list>
#include "Sort.h"
using namespace std;

void Sort::InsertSort() {
	int a[100];
	int i = 0;
	for (i = 0; i <= n - 1; i++)
		a[i] = v[i];
	int  j;
	int aux;
	for (i = 1; i <= n - 1; i++) {
		j = i - 1;
		aux = a[i];
		while ((j >= 0) && (a[j] > aux)) {
			a[j + 1] = a[j];
			j = j - 1;
			if (a[j + 1] != aux)
				a[j + 1] = aux;
		}
	}
	for (i = 0; i <= n - 1; i++) {
		this->v[i] = a[i];
	}
}

void Sort::BubbleSort() {
	int a[100];
	int i = 0, n1, ultim;
	for (i = 0; i <= n - 1; i++) {
		a[i] = v[i];
	}
	ultim = n - 1;
	while (ultim > 0) {
		n1 = ultim - 1;
		ultim = 0;
		for (i = 0; i <= n1; i++)
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				ultim = i;
			}
	}
	for (i = 0; i <= n - 1; i++) {
		this->v[i] = a[i];
	}
}

void Sort::Print() {
	cout << "Lista este:";
	int i = 0;
	for (i = 0; i <= n - 1; i++)cout << v[i] << " ";
}

Sort::Sort(int n, int min, int max) {
	int i = 1, x, k = 0;
	while (i <= n) {
		x = rand();
		if (x >= min && x <= max) {
			this->v[k] = x;
			i++;
			k++;
		}
	}
	this->n = k;
}


Sort::Sort(int n1, int a[100]) {
	int i;
	for (i = 0; i <= n1 - 1; i++) {
		this->v[i] = a[i];
	}
	this->n = n1;
}


void quicksort1(int v[], int st, int dr)
{
	int x, i, j;
	if (st < dr)
	{
		x = v[st];
		i = st + 1;
		j = dr;
		while (i <= j)
		{
			if (v[i] <= x)
				i++;
			if (v[j] >= x)
				j--;
			if (i<j && v[i]>x&& v[j] < x)
				swap(v[i], v[j]), i++, j--;
		}
		i--;
		v[st] = v[i];
		v[i] = x;
		quicksort1(v, st, i - 1);
		quicksort1(v, i + 1, dr);
	}
}

void Sort::QuickSort() {
	int a[100];
	int i;
	int n1 = n;
	for (i = 0; i <= n - 1; i++) {
		a[i] = v[i];
	}
	quicksort1(a, 0, n1 - 1);
	for (i = 0; i <= n - 1; i++) {
		this->v[i] = a[i];
	}
}

Sort::Sort(char s[100]) {
	int j = 0, nr = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != ',') {
			nr = nr * 10;
			nr = nr + (s[i] - 48);
		}
		else {
			this->v[j] = nr;
			j++;
			nr = 0;
		}
	}
	this->v[j] = nr;
	this->n = j + 1;
}

Sort::Sort(int count, ...)
{
	va_list v1;
	va_start(v1, count);
	for (int i = 0; i < count; i++)
	{
		v[i] = va_arg(v1, int);
	}
	n = count;
	va_end(v1);
}

Sort::Sort(initializer_list <int> a) {
	int n1 = a.size();
	int counter = 0;
	for (int x : a) {
		this->v[counter++] = x;
	}
	this->n = counter;
}


int Sort::GetElementsCount() {
	return n;
}

int Sort::GetElementFromIndex(int index) {
	return v[index-1];
}