#include "time.h"
#include <iostream>
#include <ctime>


time1::time1()
{
    srand(time(0));
    hours = 0 + rand() % 24;
    minutes = 0 + rand() % 60;
    seconds = 0 + rand() % 60;
    printf("%d:%d:%d\n", hours, minutes, seconds);
}

time1::~time1()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

void time1::printt()
{
    std::cout << hours << ":" << minutes << ":" << seconds << "\n";
} 

void operator ++ (time1& ff) //увеличение выбранного на 1
{
    setlocale(LC_ALL, "Rus");
    int b;
    std::cout << "Что увеличить: " << std::endl;
    std::cout << "1 - часы: " << std::endl;
    std::cout << "2 - минуты: " << std::endl;
    std::cout << "3 - секунды: " << std::endl;
    b = -1;
    while (b < 1 || b > 3)
    {
        std::cin >> b;
        if (b < 1 || b > 3)
            std::cout << "Ошибка ввода!" << std::endl;
    }
    if (b == 1) {
        ++ff.hours;
        sort(&ff.hours, &ff.minutes, &ff.seconds);
         }
    if (b == 2) {
        ++ff.minutes;
        sort(&ff.hours, &ff.minutes, &ff.seconds);
         }
    if (b == 3 ) {
        ++ff.seconds;
        sort(&ff.hours, &ff.minutes, &ff.seconds);
         }
}

time1& time1::operator ++ (int) // увеличение выбранного на пользов числ
{
    setlocale(LC_ALL, "Rus");
    int a, b;
    std::cout << "Что увеличить: " << std::endl;
    std::cout << "1 - часы: " << std::endl;
    std::cout << "2 - минуты: " << std::endl;
    std::cout << "3 - секунды: " << std::endl;
    b = -1;
    while (b < 1 || b > 3)
    {
        std::cin >> b;
        if (b < 1 || b > 3)
            std::cout << "Ошибка ввода!" << std::endl;
    }
    std::cout << "На какое число увеличить: " << std::endl;
    std::cin >> a;
    if (b == 1) {
        hours += a;
        sort(&hours, &minutes, &seconds); }
    if (b == 2) {
        minutes += a;
        sort(&hours, &minutes, &seconds); }
    if (b == 3 ) {
        seconds += a;
        sort(&hours, &minutes, &seconds); }
    return *this;
}

void operator -- (time1& ff) //уменьшаем выбранное на 1
{
    setlocale(LC_ALL, "Rus");
    int b;
    std::cout << "Что уменьшить: " << std::endl;
    std::cout << "1 - часы: " << std::endl;
    std::cout << "2 - минуты: " << std::endl;
    std::cout << "3 - секунды: " << std::endl;
    b = -1;
    while (b < 1 || b > 3)
    {
        std::cin >> b;
        if (b < 1 || b > 3)
            std::cout << "Ошибка ввода!" << std::endl;
    }
    if (b == 1) {
        --ff.hours;
        sort(&ff.hours, &ff.minutes, &ff.seconds);
         }
    if (b == 2) {
        --ff.minutes;
        sort(&ff.hours, &ff.minutes, &ff.seconds);
         }
    if (b == 3 ) {
        --ff.seconds;
        sort(&ff.hours, &ff.minutes, &ff.seconds);
         }
}

time1& time1::operator -- (int) //уменьшаем выбранное на польз число
{
    setlocale(LC_ALL, "Rus");
    int a, b;
    std::cout << "Что уменьшить: " << std::endl;
    std::cout << "1 - часы: " << std::endl;
    std::cout << "2 - минуты: " << std::endl;
    std::cout << "3 - секунды: " << std::endl;
    b = -1;
    while (b < 1 || b > 3)
    {
        std::cin >> b;
        if (b < 1 || b > 3)
            std::cout << "Ошибка ввода!" << std::endl;
    }
    std::cout << "На какое число уменьшить: " << std::endl;
    std::cin >> a;
    if (b == 1) {
        hours -= a;
        sort(&hours, &minutes, &seconds); }
    if (b == 2) {
        minutes -= a;
        sort(&hours, &minutes, &seconds); }
    if (b == 3 ) {
        seconds -= a;
        sort(&hours, &minutes, &seconds); }
    return *this;
}

void sort(int *h, int *m, int *s)
{
    while (1)
    {
        if (*h > 23) { (*h) -= 24; }
        else if (*m > 59) { (*h)++; (*m) -= 60; }
        else if (*s > 59) { (*m)++; (*s) -= 60; }
        else if (*h < 0) { (*h) += 24; /* *m = 0; *s = 0; */ }
        else if (*m < 0) { (*h)--; (*m) += 60; }
        else if (*s < 0) { (*m)--; (*s) += 60; }
        else { break; }
    }
    return;
}
