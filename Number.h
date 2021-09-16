#pragma once
#include <iostream>
using namespace std;
class Number {
	const char* value;
	int base;
public:
	Number(const char* value, int base):value(value), base(base) {};
	~Number() {
		value = nullptr;
	};
    Number operator+(Number n2);
	friend Number operator-(Number n1, Number n2);
	friend int operator>(Number n1,Number n2);
	bool operator<(Number n);
	bool operator==(Number n1);
	bool operator<=(Number n);
	bool operator>=(Number n);
    Number& operator=(const char* s);
	Number& operator=(long);
	Number operator--(int x);
	Number& operator+=(Number n);
	Number operator=(Number n);
	Number(const Number& n);
	Number(Number&& n);
	Number& operator--();
	char operator [](int index);
	void SwitchBase(int newBase);
	int  GetDigitsCount();
	int  GetBase();
	void Print();
	void compara();
};


