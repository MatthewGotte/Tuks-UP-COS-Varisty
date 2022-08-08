#include "item.h"
#include <iostream>
#include <string>

template <class T>
item<T>::item(T t) {
    this->data = t;
}

template <class T>
item<T>::~item() {
    std::cout << this->data << " Deleted" << std::endl;
}

template <class T>
T item<T>::getData() {
    return this->data;
}