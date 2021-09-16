#include "Number.h"
#include <iostream>
#include <string.h>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;

void tranformationbase10(int& x, char* s, int base) {
	int a;
	a = strlen(s);
	x = 0;
	for (int i = 0; i < strlen(s) ; i++) {
		if(s[i]=='A')x = x + 10 * (int)pow(base, a - 1);
		else if (s[i] == 'B')x=x+11* (int)pow(base, a - 1);
		else if (s[i] == 'C')x = x + 12 * (int)pow(base, a - 1);
		else if (s[i] == 'D')x = x + 13 * (int)pow(base, a - 1);
		else if (s[i] == 'E')x = x + 14 * (int)pow(base, a - 1);
		else if (s[i] == 'F')x = x + 15 * (int)pow(base, a - 1);
		else x = x + (s[i] - 48) * (int)pow(base, a - 1);
		a--;
	}
}

char* transformation(long x, int base) {
	char* s = new char[10];
	int i = 0;
	while (x != 0) {
		if (x % base < 10)
			s[i] = x % base + 48;
		else if (x % base == 10)s[i] = 'A';
		else if (x % base == 11)s[i] = 'B';
		else if (x % base == 12)s[i] = 'C';
		else if (x % base == 13)s[i] = 'D';
		else if (x % base == 14)s[i] = 'E';
		else if (x % base == 15)s[i] = 'F';
		x = x / base;
		i++;
	}
	s[i] = NULL;
	for (i = 0; i <= strlen(s) / 2; i++)
		swap(s[i], s[strlen(s) - i - 1]);
	return s;

}



Number Number::operator+( Number n2)
{
	char s1[10], s2[10];
	strcpy_s(s1, value);
	strcpy_s(s2, n2.value);
	int x, y;
	int base1, base2;
	base1 = base;
	base2 = n2.base;
	tranformationbase10(x, s1, base1);
	tranformationbase10(y, s2, base2);
	int suma;
	suma = x + y;
	char* s = new char[20];
	if (base1 >= base2)s = transformation(suma, base1);
	else s = transformation(suma, base2);
	value = s;
	if (base1 < base2)base = n2.base;
	Number res(value , base);
	return res;

}

Number operator-(Number n1, Number n2)
{
	char s1[10], s2[10];
	strcpy_s(s1, n1.value);
	strcpy_s(s2, n2.value);
	int x, y;
	int base1, base2;
	base1 = n1.base;
	base2 = n2.base;
	tranformationbase10(x, s1, base1);
	tranformationbase10(y, s2, base2);
	int dif;
	dif = x - y;
	char* s = new char[20];
	if (base1 >= base2) s = transformation(dif, base1);
	else s = transformation(dif, base2);
	n1.value = s;
	if (base1 < base2)n1.base = n2.base;
	Number res(n1.value, n1.base);
	return res;

}

int operator>(Number n1, Number n2)
{
	int x, y;
	char* s1 = new char[20];
	char* s2 = new char[20];
	s1 = (char*)n1.value;
	s1 =(char*) n2.value;
	tranformationbase10(x, s1, n1.base);
	tranformationbase10(y, s2, n2.base);
	if (x > y)return 1;
	else return 0;
}

bool Number::operator<(Number n)
{
	int x, y;
	char s1[10], s2[10];
	strcpy_s(s1, value);
	strcpy_s(s2, n.value);
	tranformationbase10(x, s1, base);
	tranformationbase10(y, s2, n.base);
	if (x < y)return 1;
	else return 0;

}

bool Number::operator==(Number n1)
{
	int x, y;
	char s1[10], s2[10];
	strcpy_s(s1, value);
	strcpy_s(s2, n1.value);
	tranformationbase10(x, s1, base);
	tranformationbase10(y, s2, n1.base);
	if (x == y)return 1;
	else return 0;
}

bool Number::operator<=(Number n)
{
	int x, y;
	char s1[10], s2[10];
	strcpy_s(s1, value);
	strcpy_s(s2, n.value);
	tranformationbase10(x, s1, base);
	tranformationbase10(y, s2, n.base);
	if (x <= y)return 1;
	else return 0;
}

bool Number::operator>=(Number n)
{
	int x, y;
	char s1[10], s2[10];
	strcpy_s(s1, value);
	strcpy_s(s2, n.value);
	tranformationbase10(x, s1, base);
	tranformationbase10(y, s2, n.base);
	if (x >= y)return 1;
	else return 0;
}



Number& Number::operator=(const char* s)
{
	value = s;
	base = 10;
	return (*this);
}

Number& Number::operator=(long x)
{
	char* s = new char[20];
	int i = 0;
	while (x != 0) {
		s[i] = x % 10 + 48;
		i++;
		x = x / 10;
	}
	s[i] = NULL;
	for (i = 0; i <= strlen(s) / 2; i++)
		swap(s[i], s[strlen(s) - 1 - i]);
	value = s;
	base = 10;
	return (*this);

}

Number Number::operator--(int)
{
	char s[10];
	strcpy_s(s, value);
	int x = 0;
	tranformationbase10(x, s, base);
	x = x / 10;
	value = transformation(x, base);
	return Number(value, base);
}

Number& Number::operator+=(Number n)
{
	char s1[10], s2[10];
	strcpy_s(s1, value);
	strcpy_s(s2, n.value);
	int x, y;
	int base1, base2;
	base1 = base;
	base2 = n.base;
	tranformationbase10(x, s1, base1);
	tranformationbase10(y, s2, base2);
	int suma;
	suma = x + y;
	char* s = new char[20];
	if (base1 >= base2)s = transformation(suma, base1);
	else s = transformation(suma, base2);
	value = s;
	if (base1 < base2)base = n.base;
	return (*this);
}


Number Number::operator=(Number n)
{
		value = n.value;
		base = n.base;
		return Number(value, base);
}

Number::Number(const Number& n)
{
	value = n.value;
	base = n.base;
}

Number::Number(Number&& n)
{
	value = n.value;
	base = n.base;
	n.value = nullptr;
	n.base = NULL;
}

Number& Number::operator--()
{
	char s[10];
	strcpy_s(s, value);
	strcpy(s + 0, s + 1);
	int x;
	tranformationbase10(x, s, base);
	value = transformation(x, base);
	return (*this);
}

char Number::operator[](int index)
{
	return this->value[index];
}



void Number::SwitchBase(int newBase)
{
	int x;
	int baza = this->base;
	char s[10];
	strcpy_s(s, this->value);
	tranformationbase10(x, s, baza);
	char* a = new char[10];
	a = transformation(x, newBase);
	this->value = a;
	this->base = newBase;
}

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

int Number::GetBase() {
	return this->base;
}

void Number::Print() {
	cout << this->value;
}
