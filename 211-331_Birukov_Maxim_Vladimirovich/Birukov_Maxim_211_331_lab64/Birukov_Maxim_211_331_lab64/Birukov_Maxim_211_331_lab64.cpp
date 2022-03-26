#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set <string> data_set;
    set <string> data_rep;
    string name;
    cout << "Enter student name: ";
    cin >> name;

    // заполнение множеств
    while (name != "-") {
        if (data_set.find(name) != data_set.end())
            data_rep.insert(name);
        data_set.insert(name);

        cout << "Enter student name: ";
        cin >> name;
    }

    //очистка основного множества
    for (auto i : data_rep)
        data_set.erase(i);

    // вывод итогового множества
    cout << "\nAnswer:\n";
    for (auto i : data_set)
        cout << "\x1b[32m[+] " << i << "\x1b[37m\n";

    // вывод хитрых 
    for (auto i : data_rep)
        cout << "\x1b[31m[-] " << i << "\x1b[37m\n";
}