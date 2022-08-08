#ifndef DLL_H
#define DLL_H

#include "ditem.h"

template <class T>
class dLL {

private:
    ditem<T> * head;
    ditem<T> * tail;
    int size;

public:
    dLL();
    ~dLL();
    ditem<T> * getHead();
    ditem<T> * getTail();
    void push(ditem<T> * newItem);
    ditem<T> * pop();
    ditem<T> * getItem(int i);
    T minNode();
    int getSize();
    void printList();

};

#endif