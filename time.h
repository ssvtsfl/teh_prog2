#pragma once
#include <iostream>

class time1
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    time1();
    ~time1();
    void printt();
    friend void operator ++ (time1& ff);; //префикс
    time1& operator ++ (int); //постфикс

    friend void operator -- (time1& ff);; //префикс
    time1& operator -- (int); //постфикс
};

void sort(int *h, int *m, int *s);

