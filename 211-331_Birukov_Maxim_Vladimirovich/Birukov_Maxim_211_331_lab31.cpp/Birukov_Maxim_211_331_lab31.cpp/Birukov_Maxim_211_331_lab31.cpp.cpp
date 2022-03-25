#include <iostream>
#include <string>
using namespace std;

void bubbl(int data[], int ctn) {
    for (int i = 0; i < ctn; i++) {
        for (int j = 0; j < ctn - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
 
    cout << endl << "Ответ: ";
    for (int i = 0; i < ctn; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}
void count_sort(int data[], int ctn) {
    cout << endl << "Ответ: ";
    for (int i = (int)'a'; i <= (int)'z'; i++) {
        for (int j = 0; j < count(data, data + ctn, i); j++) {
            cout << (char)i << " ";
        }
    }
   cout << endl;
}
int merge_arrays(int c[], int a[], int b[], int len_a, int len_b) {
    int i = 0, j = 0, poz = 0;
    while ((i < len_a) and (j < len_b)) {
        if (a[i] < b[j]) {
            *&c[poz] = a[i];
            i++;
        }
        else {
            *&c[poz] = b[j];
            j++;
        }
        poz++;
    }

    if (i < len_a) {
        for (int k = i; k < len_a; k++) {
            *&c[poz] = a[k];
            poz++;
        }
    }
    if (j < len_b) {
        for (int k = j; k < len_b; k++) {
            *&c[poz] = b[k];
            poz++;
        }
    }   
    return len_a + len_b;

}
int merge_sort(int data[], int start, int stop, int merge_end[]) {
    if (stop - start == 1) {
        *&merge_end[0] = data[start];
        return 1;
    }
    else {
        int middle = start + ((stop - start) / 2);
        int left[1000];
        int right[1000];

        int run_len = merge_sort(data, start, middle, merge_end);
        int left_len = run_len;
        for (int i = 0; i < run_len; i++) {
            left[i] = merge_end[i];
        }

        run_len = merge_sort(data, middle, stop, merge_end);
        int right_len = run_len;
        for (int j = 0; j < run_len; j++) {
            right[j] = merge_end[j];
        }

        int len_mirge = merge_arrays(merge_end, left, right, left_len, right_len);
        return len_mirge;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int menu;
    cout << "Выберите номер задания: ";
    cin >> menu;
    switch (menu) {
    case 1:
        cout << "Пузырьковая сортировка" << endl;
        break;

    case 2:
        cout << "Сортировка букв по алфавиту" << endl;
        break;

    case 3:
        cout << "Сортировка слиянием" << endl;
        break;
    }

    // Инициализация
    const int max_size = 1000;
    int data[max_size];
    string s = "";
    int ctn = 0;

    // Ввод чисел в массив
    cout << "Чтобы закончить ввод пропишите: '+'" << endl << "Элемент[" << ctn << "]: ";
    cin >> s;
    while (s != "+") {
        try {
            data[ctn] = stoi(s);
        }
        catch (invalid_argument e) {
            data[ctn] = (int)s[0];
        }
        ctn++;

        cout << "Элемент[" << ctn << "]: ";
        cin >> s;
    }


    switch (menu) {
    case 1:
        bubbl(data, ctn);
        break;

    case 2:
        count_sort(data, ctn);
        break;
    case 3:
        int ansver_arr[1000];
        int ansver_len = merge_sort(data, 0, ctn, ansver_arr);
        cout << endl << "Ответ: ";
        for (int i = 0; i < ansver_len; i++) {
            cout << ansver_arr[i] << ' ';
        }
        cout << endl;
        break;
    }

    return 0;
}