#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int, double> v;
	int n;
	double a;
	cout << "Dati numarul de elemente: ";
	cin >> n;
	cout << "Vectorul este: ";
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.Push(a);
	}
	v.Detele(2);
	cout << "Dupa stergerea elementului de pe pozitia 2 ";
	v.Print();
	cout << endl;
	v.Insert(3, 4);
	cout << "Dupa inserarea elementului 4 pe pozitia 3 ";
	v.Print();
	cout << endl;
	v.Set(2,5);
	cout << "Dupa setarea elementului 5 pe pozitia 2 ";
	v.Print();
	cout << endl;
	v.Sort(compara);
	cout << "Dupa sortare ";
	v.Print();
	cout << endl;
	v.FirstIndex(equal,3);
}