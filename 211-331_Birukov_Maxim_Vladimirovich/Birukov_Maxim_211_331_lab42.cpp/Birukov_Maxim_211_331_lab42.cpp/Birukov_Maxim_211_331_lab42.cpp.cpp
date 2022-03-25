#include <iostream>
#include <string>
using namespace std;

void point_1(string line, int point_location, int slash_location) {                          // Расширение
    cout << line.substr(point_location + 1, line.length() - point_location) << endl;
}

void point_2(string line, int point_location, int slash_location) {                          // Получение названия
    cout << line.substr(slash_location + 1, point_location - slash_location - 1) << endl;
}

void point_3(string line, int point_location, int slash_location) {                          // Получение расположения файла
    cout << line.substr(0, slash_location) << endl;
}

void point_4(string line, int point_location, int slash_location) {                          // Получение названия диска для хранения
    cout << line[0] << endl;
}

void point_5(string line, int point_location, int slash_location, string new_name) {         // Переименование файла
    string dir = line.substr(0, slash_location);
    string last_name = line.substr(slash_location + 1, line.length() - slash_location);
    const string command = "cd " + dir + " && ren " + last_name + " " + new_name;
    system(command.c_str());
}

void point_6(string line, int point_location, int slash_location) {                           // Копирование файла
    string dir = line.substr(0, slash_location);
    string last_name = line.substr(slash_location + 1, line.length() - slash_location);
    string new_name = line.substr(slash_location + 1, point_location - slash_location - 1) + "_copy.";
    new_name += line.substr(point_location + 1, line.length() - point_location);
    const string command = "cd " + dir + " && copy " + last_name + " " + new_name;
    system(command.c_str());
}

int main()
{
    string line;
    string pass;
    int menu;
    string new_name;
    cout << ">> Выберите номер задания: ";
   cin >> menu;

    while (menu != 7) {
        getline(cin, pass);  
        cout << "Путь до файла: ";
        getline(cin, line);
        int point_location, slash_location;
        for (int i = line.length() - 1; i >= 0; i--) {
            if (line[i] == '.')
                point_location = i;

            if (line[i] == (char)92) {
                slash_location = i;
                break;
            }
        }

        switch (menu) {
        case 1:
            point_1(line, point_location, slash_location);
            break;
        case 2:
            point_2(line, point_location, slash_location);
            break;
        case 3:
            point_3(line, point_location, slash_location);
            break;
        case 4:
            point_4(line, point_location, slash_location);
            break;
        case 5:
            cout << "Новое имя: ";
            cin >> new_name;
            point_5(line, point_location, slash_location, new_name);
            break;
        case 6:
            point_6(line, point_location, slash_location);
            break;
        }

       cout << ">> Выберите номер задания: ";
        cin >> menu;
    }
}