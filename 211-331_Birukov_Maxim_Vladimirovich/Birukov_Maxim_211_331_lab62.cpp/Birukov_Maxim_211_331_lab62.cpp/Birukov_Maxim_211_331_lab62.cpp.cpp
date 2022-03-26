#include <iostream>
#include <deque>
#include <string>
using namespace std;

void point_1(string line) {
    // Полиндром деком
    bool answ = true;
    deque <char> deq_line;
    for (auto i : line)
        deq_line.push_back(i);

    // Проход по деку 
    int len = round(deq_line.size() / 2.0);
    for (int i = 0; i < len; i++) {
        if (deq_line.front() == deq_line.back()) {
            if (deq_line.size() != 1) {
                deq_line.pop_front();
                deq_line.pop_back();
            }
            else if (deq_line.size() == 1) {
                deq_line.pop_front();
            }
        }
        else {
            answ = false;
        }
    }
    // Проверяем пустоту дека
    if (not deq_line.empty())
        answ = false;

    
    if (answ)
        cout << "-> Да";
    else
        cout << "-> Нет";
}

int main()
{
    cout << "Enter libe: ";
    string line_task1;
    getline(cin, line_task1);
    point_1(line_task1);

}