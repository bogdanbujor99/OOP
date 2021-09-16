#include <iostream>
#include <string.h>
using namespace std;

float operator"" _Kelvin(const char* x) {
    float a=0;
    for (int i = 0 ; i <= strlen(x)-1 ; i++) {
        a = a * 10 + (x[i]-48);
    }
    a = a - 273.15;
    return a;
}

float operator"" _Fahrenheit(const char* x) {
    float a = 0;
    for (int i = 0; i <= strlen(x) - 1; i++) {
        a = a * 10 + (x[i] - 48);
    }
    a = a - 32;
    a = a * 5;
    a = a / 9;
    return a;
}

int main()
{
    float a= 300_Kelvin;
    cout << a << endl;
    float b = 120_Fahrenheit;
    cout << b;
}


