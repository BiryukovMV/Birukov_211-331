#include <iostream>
#include <string>
using namespace std;

void print(int* arr) {
	for (int i = 1; i < arr[0]; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}


void push_back(int*& arr, int num) {
	int len = arr[0];
	arr[0]++;
	int* new_arr = new int[len + 1];
	for (int i = 0; i < len; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[len] = num;
	delete[] arr;
	arr = new_arr;
}

void point_3(int* data) {
	int ctn = data[0];
	for (int i = 1; i <= ctn; i++) {
		for (int j = 1; j <= ctn - 1 - i; j++) {
			int a = 0, b = 0, ctn = 0;
			// Сумма data[j]
			string s = to_string(data[j]);
			for (char i : s) {
				if (ctn == 1) {
					a += stoi(to_string(i));
					ctn = 0;
				}
				else {
					ctn = 1;
				}
			}
			// Сумма data[j+1]
			ctn = 0;
			s = to_string(data[j + 1]);
			for (char i : s) {
				if (ctn == 1) {
					b += stoi(to_string(i));
					ctn = 0;
				}
				else {
					ctn = 1;
				}
			}

			if (a > b) {
				swap(data[j], data[j + 1]);
			}
		}
	}
}

void std_sort(int* data) {
	int ctn = data[0];
	for (int i = 1; i <= ctn; i++) {
		for (int j = 1; j <= ctn - 1 - i; j++) {
			if (data[j] < data[j + 1]) {
				swap(data[j], data[j + 1]);
			}
		}
	}
}

void point_4(int* data) {
	std_sort(data);
	//print(data);
	int ctn = data[0];
	for (int i = 1; i <= ctn; i++) {
		for (int j = 1; j <= ctn - 1 - i; j++) {
			int a = 0, b = 0, ctn = 0;
			// Сумма data[j]
			string s = to_string(data[j]);
			for (char i : s) {
				a = stoi(to_string(i));
			}

			// Сумма data[j+1]
			ctn = 0;
			s = to_string(data[j + 1]);
			for (char i : s) {
				b = stoi(to_string(i));
			}

			if (a > b) {
				swap(data[j], data[j + 1]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL,"Rus");
	int menu;
	int* arr = new int[1]{ 1 };  
	string s;
	bool check = true;
	cout << "Выберите номер задания: ";
	cin >> menu;
	while (check) {
		switch (menu)
		{
		case 1:
			cout << "Чтобы закончить ввод наберите '+'"<< endl << "Элемент[" << arr[0] - 1 << "] : ";
			cin >> s;
			while (s != "+") {
				try {
					push_back(arr, stoi(s));
				}
				catch (invalid_argument e) {
					break;
				}

				cout << "Элемент[" << arr[0] - 1 << "]: ";
				cin >> s;
			}
			cout << endl;
			break;
		case 2:
			print(arr);
			break;
		case 3:
			point_3(arr);
			print(arr);
			break;
		case 4:
			point_4(arr);
			print(arr);
			break;
		case 5:
			check = false;
		}

		if (check) {
			cout << "Выберите номер задания: ";
			cin >> menu;
		}
	}


	delete[] arr;
	return 0;
}