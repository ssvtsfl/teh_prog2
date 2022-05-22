#include <iostream>
#include <string>
#include <ctime>
#include "time.h"
#include "ocher.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int flag = 1, c;
    
    time1 a;
    while (flag == 1)
    {
        cout << "Задание №1 - Унарная операция" << endl;
        cout << "1 - Префиксный оператор ++ для увеличение на 1" << endl;
        cout << "2 - Префиксный оператор -- для уменьшение на 1" << endl;
        cout << "3 - Постфиксный оператор ++ для увеличения на пользовательское число" << endl;
        cout << "4 - Постфиксный оператор -- для уменьшения на пользовательское число" << endl;
        cout << "5 - Переход ко второму заданию работы" << endl;
        cout << "--> ";
        c = -1;
        while (c < 1 || c >5)
        {
            cin >> c;
            if (c < 0 || c>5)
                cout << "Ошибка ввода!" << endl;
        }
        switch (c)
        {
        case 1:
                ++a;
                a.printt();
            break;
        case 2:
                --a;
                a.printt();
            break;
        case 3:
                a++;
                a.printt();
            break;
        case 4:
                a--;
                a.printt();
            break;
        case 5: //0 - Выход
            cout << "\n";
            flag = 0;
            break;
        }
    } 

   //ЗАДАНИЕ №2
    
    int bb, chislo, n = 0, o1;
    flag = 1;
    cout << "Введите количество очередей" << endl;
    int k, v;
    cin >> k;
    ocher1 *b = new ocher1[k];
    
    for (int i = 0; i < k; i++)
    {
        cout << "Введите длину очереди под номером " << i << endl;
        cin >> v;
        srand(time(0));
        for(int j = 0; j < v; j++)
        {
            b[i].push(10 + rand()%10);
        }
    }
    while (flag == 1)
    {
        cout << "Задание №2 - Бинарная операция" << endl;
        cout << "1 - Добавление элемента в очередь" << endl;
        cout << "2 - Извлечение элемента из очереди" << endl;
        cout << "3 - Сложение" << endl;
        cout << "4 - Вычитание" << endl;
        cout << "5 - Вывод очереди" << endl;
        cout << "6 - Выберите очередь" << endl;
        cout << "7 - Умножение" << endl;
        cout << "8 - Деление" << endl;
        cout << "0 - Выход" << endl;
        cout << "-> ";
        c = -1;
        while (c < 0 || c >9)
        {
            cin >> c;
            if (c < 0 || c>8)
                cout << "Ошибка ввода!" << endl;
        }
        switch (c)
        {
        case 1:
                cin >> bb;
                b[n] += bb;
            break;
        case 2:
                b[n] -= 0;
            break;
        case 3:
                cout << "Какие очереди сложить" << endl;
                cin >> n;
                cin >> o1;
                if(b[n].get_size() == b[o1].get_size())
                    b[n] = b[n] + b[o1];
                else {
                    cout << "Введите две одинаковые очереди!" << endl;
                    break; }
            break;
        case 4:
                cout << "Какие очереди вычесть" << endl;
                cin >> n;
                cin >> o1;
                if(b[n].get_size() == b[o1].get_size())
                    b[n] = b[n] - b[o1];
                else {
                    cout << "Введите две одинаковые очереди!" << endl;
                    break; }
            break;
        case 5:
                b[n].print();
            break;
        case 6:
                cout << "Введите номер очереди" << endl;
                cin >> n;
                if(n >= k){
                    cout << "Ошибка ввода!" << endl;
                    break;}
                    else b[n].print();
            break;
        case 7:
                cout << "Какие очереди умножить" << endl;
                cin >> n;
                cin >> o1;
                if(b[n].get_size() == b[o1].get_size())
                    b[n] = b[n] * b[o1];
                else {
                    cout << "Введите две одинаковые очереди!" << endl;
                    break; }
            break;
        case 8:
                cout << "Введите число" << endl;
                cin >> chislo;
                b[n] = b[n] / chislo;
            break;
        case 0: //0 - Выход
            cout << "\n";
            flag = 0;
            break;
        }
    }
    return 0;
}
