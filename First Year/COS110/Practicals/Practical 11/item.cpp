#include "item.h"

template <class T>
item<T>::item(T t) {
    this->next = nullptr;
    this->data = t;
}

template <class T>
item<T>::~item() {
    this->next = nullptr;
}

template <class T>
T item<T>::getData() {
    return this->data;
}