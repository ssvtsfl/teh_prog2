#pragma once
#include <iostream>

typedef struct element
{
    int x;
    element* prev;
} element;

class ocher1
{
private:
    int size = 0;
    element* pravo = nullptr;

public:
    ocher1();
    ~ocher1();
    void set_size(int &help);
    int get_size();
    void push(int bb); //заполнение очереди
    friend ocher1& operator +=(ocher1& b, int bb); //добавление
    int pop(); // извлечение
    int operator-=(int o); // извлечение
    void print(); // вывод
    ocher1& operator+(ocher1& p); // сложение двух экземпл
    friend ocher1& operator-(ocher1&, ocher1&); // вычитание экземл
    ocher1& operator*(ocher1& u); // поэлемент умножение экземл
    ocher1& operator/ (int ); // деление на пользоват число
};

