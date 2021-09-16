#pragma once
#include<iostream>
class Compare {
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class comparator:public Compare{
public:
	int CompareElements(void* e1, void* e2) {
		if (e1 > e2)return 1;
		else if (e1 < e2)return -1;
		else return 0;
	}
};

