#include <iostream>
#include <queue>
using namespace std;

bool primfacs(int n) {
    bool is_235 = true;
    int i = 2;
    // идём до простого числа на ++
    while (i * i <= n) {
        while (n % i == 0) {
            if (i != 2 and i != 3 and i != 5)
                is_235 = false;
            n /= i;
        }
        i++;
    }
    if (n > 1 and n != 2 and n != 3 and n != 5)
        is_235 = false;

    return is_235;
}

int main()  // очереди
{
    queue <int> data;
    int end_num;
    cout << "Enter max num: ";
    cin >> end_num;

    //загружаем очередь 
    for (int i = 2; i <= end_num; i++) {
        if (primfacs(i))
            ///cout << i << ' ';
            data.push(i);
    }
    //выгружаем очередь
    int len = data.size();
    for (int i = 0; i < len; i++) {
        cout << data.front() << ' ';
        data.pop();
    }
}