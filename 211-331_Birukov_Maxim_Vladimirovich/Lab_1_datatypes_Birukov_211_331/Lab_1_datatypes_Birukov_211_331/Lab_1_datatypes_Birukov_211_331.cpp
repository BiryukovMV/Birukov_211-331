#include <iostream>
#include <bitset>
#include <cfloat>
#include <limits.h>
#include <stdio.h>
using namespace std;

int main()
{
	cout << "1)Birukov Maxim Vladimirovich 211-331" << endl; // Выводит ФИО и номер группы на экран

	cout << "2)" << endl;
	cout << "min int =" << INT_MIN << "," << "max int =" << INT_MAX << "," << "size of int = " << sizeof(int) << endl;
	cout << "min unsigned int =" << 0 << "," << "max unsigned int =" << UINT_MAX << "," << "size of unsigned int = " << sizeof(unsigned int) << endl;
	cout << "min short =" << SHRT_MIN << "," << "max short =" << SHRT_MAX << "," << "size of short = " << sizeof(short) << endl;
	cout << "min unsigned short =" << 0 << "," << "max unsigned short =" << USHRT_MAX << "," << "size of unsigned short = " << sizeof(unsigned short) << endl;
	cout << "min long =" << LONG_MIN << "," << "max long =" << LONG_MAX << "," << "size of long = " << sizeof(long) << endl;
	cout << "min long long =" << LLONG_MIN << "," << "max long long =" << LLONG_MAX << "," << "size of long long = " << sizeof(long long) << endl;
	cout << "min double =" << DBL_MIN << "," << "max double =" << DBL_MAX << "," << "size of double = " << sizeof(double) << endl;
	cout << "min char =" << CHAR_MIN << "," << "max char =" << CHAR_MAX << "," << "size of char = " << sizeof(char) << endl;
	cout << "min bool = 0(false)" << "," << "max bool = 1(true)" << "," << "size of bool = " << sizeof(bool) << endl; // Минимальные и максимальные значения встроенных типов данных, а так же их размер

	cout << "3)" << endl;
	int num;
	cin >> num;
	cout << "Binary :  " << bitset<16>(num) << endl;
	cout << "16:  " << hex << num << endl;
	cout << "bool = " << bool(num) << endl;
	cout << "double = " << double(num) << endl;
	cout << "char = " << char(num) << endl;
	cout << endl;

	cout << "4)" << endl;
	int a, b;
	cout << "Enter values a * x = b: ";
	cin >> a >> b;
	cout << dec << a << " * x = " << b << endl;
	cout << "x = " << b << " / " << a << endl;
	cout << "x = " << double(b) / double(a) << endl;
	cout << "Answer: " << double(b) / double(a) << endl;

	cout << "5)" << endl;
	int c, d;
	cout << "Enter the coordinates: ";
	cin >> c >> d;
	cout << "The middle of the segment: " << (double(c) + double(d)) / 2;
}
