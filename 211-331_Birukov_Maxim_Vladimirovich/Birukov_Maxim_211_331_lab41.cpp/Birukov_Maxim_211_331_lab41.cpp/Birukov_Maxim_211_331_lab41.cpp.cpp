#include <iostream>
#include <string>
#include <map>
using namespace std;

void point_1() {
	cout << "Строка: ";
	string line_1, line_2 = "";
	getline(cin, line_1); 
	getline(cin, line_1);

	int len = line_1.length();
	int plus = 0;
	for (int i = 0; i < len; i++) {
		if (line_1[i] != ' ')
			line_2 += tolower(line_1[i]);
	}

	len = line_2.length();
	bool ans = true;
	for (int i = 0; i < len; i++) {
		if (line_2[i] != line_2[len - 1 - i]) {
			ans = false;
			break;
		}
	}
	cout << endl;
	if (ans)
		cout << "Да" << endl;
	else
		cout << "Нет" << endl;
}

void point_2() {
	// Алгоритм Бойера - Мура
	int ctn = 0;

	string line;			
	cout << "Строка: ";		
	getline(cin, line);	
	getline(cin, line);	

	string word;			
	cout << "Подстрока: ";	
	getline(cin, word);	

	string reverse_word = "";
	for (auto i : word) {
		reverse_word = i + reverse_word;
	}
	map<char, int> data;
	int now = word.length() - 1;
	bool is_word = true;
	// Создание карты значений
	for (int i = (word.length() - 1); i >= 0; i--) {
		if (data.find(word[i]) == data.end()) {
			if (word[i] == word[word.length() - 1]) {
				data.insert(pair<char, int>((char)word[i], word.length()));
			}
			else {
				data.insert(pair<char, int>(word[i], ctn));
			}
		}
		else if (word[i] == word[word.length() - 1]) {
			data[word[i]] = ctn;
		}
		ctn++;
	}
	// Поиск подстроки
	cout << endl;
	while (now < line.length()) {
		bool is_word = true;
		int run_now = now;
		for (auto i : reverse_word) {
			if (i == line[run_now]) {
				run_now--;
			}
			else {
				is_word = false;
				break;
			}
		}
		if (is_word) {
			cout << "Индекс: " << now - word.length() + 1 << endl;
			now += word.length();
		}
		else {
			if (data.find(line[run_now]) != data.end()) {
				now += data[line[run_now]];
			}
			else {
				now += word.length();
			}
		}
	}
}

void point_3() {
	// Шифр Цезаря
	int shift;
	string line;
	cout << "Строка: ";
	getline(cin, line);  
	getline(cin, line);
	cout << "Сдвиг: ";
	cin >> shift;
	cout << endl << "Ответ: ";
	for (auto i : line) {
		if ((('A' <= i) && (i <= 'Z')) || (('a' <= i) && (i <= 'z'))) {
			cout << (char)((int)i + shift);
		}
		else {
			cout << i;
		}
	}
	cout << endl;  
}

void point_4() {
	string line, pass;
	cout << "Строка: ";
	getline(cin, pass);  
	getline(cin, line);
	bool is_out = false;

	cout << endl << "Ответ: ";
	for (auto i : line) {
		if (i == '"') {
			is_out = not is_out;
			if (not is_out)
				cout << " | ";
		}
		else {
			if (is_out)
				cout << i;
		}
	}
	cout << "\b\b\n";

}

int main()
{
	setlocale(LC_ALL, "Rus");
	int menu;
	cout << "Выберите номер задания (нажмите 5 для выхода): ";
	cin >> menu;
	while (menu != 5) {
		if (menu == 1) {
			cout << " Задание 1" << endl;
			point_1();
		}
		else if (menu == 2) {
			cout << "Задание 2" << endl;
			point_2();
		}
		else if (menu == 3) {
			cout << "Задание 3 " << endl;
			point_3();
		}
		else if (menu == 4) {
			cout << "Задание 4 " << endl;
			point_4();
		}

		cout << "Выберите номер задания (нажмите 5 для выхода): ";
		cin >> menu;
	}

}