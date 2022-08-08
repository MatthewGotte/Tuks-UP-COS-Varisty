#include "orderedContainer.h"

template <class T>
OrderedContainer<T>::OrderedContainer(LinearStructure<T> *c) {
    dataStructure = c->clone();
}

template <class T>
OrderedContainer<T>::OrderedContainer(const OrderedContainer<T> &other) {
    OrderedContainer<T> * newContainer;
    newContainer->dataStructure = other.dataStructure->clone();
}

template <class T>
OrderedContainer<T> & OrderedContainer<T>::operator=(const OrderedContainer<T> &other) {
    OrderedContainer<T> * newContainer;
    newContainer->dataStructure = other.dataStructure->clone();
    return *newContainer;
}

template <class T>
OrderedContainer<T>::~OrderedContainer<T>() {
    //delete dataStructure;
}

template <class T>
bool OrderedContainer<T>::isEmpty() {
    /*if (!dataStructure->isEmpty()) {
        return true;
    }
    return false;*/
    return dataStructure->isEmpty();
}

template <class T>
LinearStructure<T> * OrderedContainer<T>::getImplementation() {
    return this->dataStructure;
}
