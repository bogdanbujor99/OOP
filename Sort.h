#pragma once
#include <initializer_list>
using namespace std;

class Sort
{private:
	int* v = new int[100];
	int n;
public:
	Sort(int n, int min, int max);
	Sort(initializer_list <int> a);
	Sort(int n1, int a[100]);
	Sort(int count, ...);
	Sort(char s[100]);
	void InsertSort();
	void QuickSort();
	void BubbleSort();
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};
