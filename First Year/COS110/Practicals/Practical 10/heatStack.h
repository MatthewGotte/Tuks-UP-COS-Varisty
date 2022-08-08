#ifndef HEATSTACK_H
#define HEATSTACK_H

#include "heatNode.h"

template <class T>
class heatStack {

private:
    heatNode<T> * top;

public:
    heatStack();
    ~heatStack();
    void push(heatNode<T> * t);
    void pop();
    heatNode<T> * peek();
    void print();
    bool validateCooling(int * heat, int numSinks);

};

#endif