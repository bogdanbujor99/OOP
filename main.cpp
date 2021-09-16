#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
	//EXEMPLU PENTRU PRIMUL CONSTRUCTOR SI INSERT SORT
	Sort d1(4, 5, 9);
	d1.InsertSort();
	d1.Print();
	cout << endl;

	//EXEMPLU PENTRU AL 2 LEA CONSTRUCTOR SI QUICK SORT
	Sort d2 = { 4,1,3,44,34 };
	d2.QuickSort();
	d2.Print();
	cout << endl;

	//EXEMPLU PENTRU AL 3 LEA CONSTRUCTOR SI BUBBLE SORT
	int a[100] = { 2,1,9,8,5 };
	int n1 = 5;
	Sort d3(n1, a);
	d3.BubbleSort();
	d3.Print();
	cout << endl;

	//EXEMPLU PENTRU AL 4 LEA CONSTRUCTOR
	Sort d4(5, 3, 6, 1, 2, 4);
	d4.InsertSort();
	d4.Print();
	cout << endl;

	//EXEMPLU PENTRU AL 5 LEA CONSTRUCTOR
	char s[100] = "67,89,34,55";
	Sort d5(s);
	d5.InsertSort();
	d5.Print();
	cout << endl;

	//EXEMPLU PENTRU GetElementsCount pentru d5
	cout << "Sunt " << d5.GetElementsCount() << " elemente in lista." << endl;

	//EXEMPLU PENTRU  GetElementFromIndex PENTRU d5
	cout << "Al 3 lea numar din lista este : " << d5.GetElementFromIndex(3) << endl;

}


