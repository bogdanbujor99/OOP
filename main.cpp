#include<iostream>
#include"classArray.h"
#include"Compare.h"
using namespace std;

int compare(const int& a, const int& b) {
	//cout << a << " " << b << endl;
	if (a > b)return 1;
	else if (a < b)return -1;
	else return 0;
}

int main() {
	Array<int> d(2);
	int x = 1;
	d += x;
	Array<int> a(d);
	a += 4;
	a += 3;
	a += 5;
	a += 2;
	cout << "Lista este:";
	ArrayIterator<int>begin = a.GetBeginIterator();
	ArrayIterator<int>end = a.GetEndIterator();
	while (begin != end) {
		cout << *begin.GetElement() << " ";
		++begin;
	}
	cout << endl;
	Compare* c = new comparator;
	a.Sort(c);
	cout << "Lista sortata este:";
	ArrayIterator<int>begin1 = a.GetBeginIterator();
	ArrayIterator<int>end1 = a.GetEndIterator();
	while (begin1 != end1) {
		cout << *begin1.GetElement() << " ";
		++begin1;
	}
	cout << endl;
	a.BinarySearch(3, compare);
	if (a.BinarySearch(3, compare) !=-1)cout << "Elementul 3 se afla pe pozitia:" << a.BinarySearch(3, compare) << endl;
	else cout << "Elementul nu se afla in lista";

}
