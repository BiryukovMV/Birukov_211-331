#include <iostream>
using namespace std;
void one()
{
	cout << "Add line " << endl;
	cout << "line = ";
	int a, b = 0, line;
	cin >> line;
	for (a = 0; b < line; a++)
	{
		cout << endl;
		for (b = 0; b <= a; b++)
			cout << b;
	}
}
void two()
{
	unsigned int a = 1, b = 1, h;
	cout << "h = ";
	cin >> h;
	switch (h)
	{
	case 0: cout << 1 << endl;
		break;
	case 1: cout << 1 << " " << endl;
		break;
	default:
		cout << 1 << " ";
		for (b = 1; b <= h; b++)
		{
			a = (a * (h - (b - 1))) / b;
			cout << a << " ";
		}
		cout << endl;
		break;
	}
}

void three()
{
	int z, sum = 0, v, x;
	cin >> z;
	for (v = 0; v < z; v++)
	{
		cin >> x;
		sum = sum + x;
	}
	cout << 1. * (sum / z);
}

int main() {
	setlocale(LC_ALL, "Rus");
	int d = 0;
	while (d != 4)
	{
		cout << endl << "Меню" << endl <<
			"1. Задание 1 " << endl <<
			"2. Задание 2 " << endl <<
			"3. Задание 3 " << endl <<
			"4. Выход " << endl <<
			"Выберите операцию: ";
		cin >> d;
		switch (d)
		{
		case 1:one();
			break;
		case 2:two();
			break;
		case 3:three();
			break;
		case 4: 
			break;
		default: return 0;
		}
	}
	return 0;
}