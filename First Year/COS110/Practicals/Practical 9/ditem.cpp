#ifndef DITEM_CPP
#define DITEM_CPP
#include "ditem.h"
#include <iostream>

template <class T>
ditem<T>::ditem(T t) {
    this->data = t;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
ditem<T>::~ditem() {
    std::cout << this->data << " Deleted" << std::endl;
}

template <class T>
T ditem<T>::getData() {
    return this->data;
}

#endif