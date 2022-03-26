#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

int main()
{
    map <string, string> poz;
    list <string> data;
    string line;

    cout << "Student: ";
    getline(cin, line);
    while (line != "-") {
        if (poz.find(line.substr(0, line.find(' '))) != poz.end()) {
            // слово есть
            auto num = ++find(data.begin(), data.end(), poz[line.substr(0, line.find(' '))]);
            data.insert(num, line);
            // меняем последню строку
            poz[line.substr(0, line.find(' '))] = line;
        }
        else {
            // слова нет 
            data.push_back(line);
            poz.insert(pair<string, string>(line.substr(0, line.find(' ')), line));
        }

        cout << "Student: ";
        getline(cin, line);
    }

    // вывод листа
    cout << "\nAnswer:\n";
    for (auto i = data.begin(); i != data.end(); i++) {
        cout << *i << '\n';
    }
}