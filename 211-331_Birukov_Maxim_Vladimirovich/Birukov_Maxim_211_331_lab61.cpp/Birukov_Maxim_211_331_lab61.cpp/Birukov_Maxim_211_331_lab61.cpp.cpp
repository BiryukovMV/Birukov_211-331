#include <iostream>
#include <string>
#include <map>
#include <stack>  
using namespace std;

int main() {
    bool answ = true;
    map<char, char> data;
    data.insert(pair<char, int>('{', '}')); 
    data.insert(pair<char, int>('[', ']'));  
    data.insert(pair<char, int>('(', ')'));  
   
    stack <char> main_steck;
    string line_start;
    cin >> line_start;
    
    for (auto i : line_start) {
        if (i == '{' or i == '(' or i == '[') {
            main_steck.push(i); 
        }
        else if (i == '}' or i == ')' or i == ']') {
            if (i == data[main_steck.top()]) {
                main_steck.pop();
            }
            else {
                answ = false;
                break;
            }
        }
    }
   
    if (not main_steck.empty())
        answ = false;
    
    if (answ)
        cout << "-> Yes";
    else
        cout << "-> No";
}