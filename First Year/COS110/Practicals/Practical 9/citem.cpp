#ifndef CITEM_CPP
#define CITEM_CPP
#include "citem.h"
#include <iostream>

template <class T>
citem<T>::citem(T t) {
    this->data = t;
    this->next = nullptr;
}

template <class T>
citem<T>::~citem<T>() {
    std::cout << this->data << " Deleted" << std::endl;
}

template <class T>
T citem<T>::getData() {
    return this->data;
}

#endif