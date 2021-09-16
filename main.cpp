#include <iostream>
#include "Number.h"
using namespace std;



int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number* n3 = NULL;
	n1.SwitchBase(10);
	cout << "n1 este: ";
	n1.Print();
	cout << endl;
	(n1 += n1) += n1;
	n1.Print();
	n1 = n2 + n1;
}

