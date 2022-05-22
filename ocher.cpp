#include "ocher.h"
#include <iostream>

ocher1::ocher1()
{
    size = 0;
    pravo = 0;
}

ocher1::~ocher1() //деструктор
{
    element* tmp = pravo;
    while(size != 0) {
        element* y = tmp;
        tmp = tmp->prev;
        y->x = 0;
        size--;
        delete y;
    }
}

void ocher1::set_size(int &help)
{
    size = help;
}

int ocher1::get_size() { return size; }

void ocher1::push(int bb)
{
    element* tmp = new element;
    tmp->prev = pravo;
    tmp->x = bb;
    pravo = tmp;
    size++;
} 

ocher1& operator+=(ocher1& b, int bb)
{
    element* tmp = new element;
    tmp->prev = b.pravo;
    tmp->x = bb;
    b.pravo = tmp;
    b.size++;
    return b;
}

void ocher1::print()
{
    element* tmp = pravo;
    for (int i = 0; i < size; i++) {
        std::cout << tmp->x << "-->" ;
        tmp = tmp->prev;
    }
    std::cout << "\n";
}

int ocher1::pop()
{
    element* tmp = pravo;
    for (int i = 0; i < size-1; i++)
    {
        tmp = tmp->prev;
    }
    int i = tmp->x;
    std::cout << tmp->x;
    tmp->prev = nullptr;
    tmp->x = NULL;
    size--;
    std::cout << "\n";
    return i;
}

int ocher1::operator-=(int o)
{
    int i = this->pop();
    return i;
}

ocher1& ocher1::operator+(ocher1& p)
{
    element *tmp = this->pravo;
    element *tmp1 = p.pravo;
    for(int i = 0; i < size; i++){
        std::cout << tmp->x + tmp1->x <<  "-->";
        tmp->x += tmp1->x;
        tmp = tmp ->prev;
        tmp1 = tmp1 ->prev;
    }
    std::cout << "\n";
    return *this;
}

ocher1& operator-(ocher1& o, ocher1& m)
{
    element *tmp = o.pravo;
    element *tmp1 = m.pravo;
    for(int i = 0; i < m.size; i++){
        std::cout << tmp->x - tmp1->x <<  "-->";
        tmp->x -= tmp1->x;
        tmp = tmp ->prev;
        tmp1 = tmp1 ->prev;
    }
    std::cout << "\n";
    return o;
}

ocher1& ocher1::operator*(ocher1& u)
{
    element *tmp = this->pravo;
    element *tmp1 = u.pravo;
    for(int i = 0; i < size; i++){
        std::cout << tmp->x * tmp1->x <<  "-->";
        tmp->x *= tmp1->x;
        tmp = tmp ->prev;
        tmp1 = tmp1 ->prev;
    }
    std::cout << "\n";
    return *this;
}

ocher1& ocher1::operator/(int chislo)
{
    element *tmp = pravo;
    if(chislo != 0){
        for(int i = 0; i < size; i++){
            std::cout << tmp->x / chislo <<  "-->";
            tmp->x /= chislo;
            tmp = tmp ->prev;
        }
    }
    std::cout << "\n";
    return *this;
}
