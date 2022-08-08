#ifndef HEATNODE_CPP
#define HEATNODE_CPP

#include "heatNode.h"

#include <iostream>

template <class T>
heatNode<T>::heatNode(T i, int p) {
    this->coolantLevel = i;
    this->power = p;
    this->next = nullptr;
}

template <class T>
heatNode<T>::~heatNode<T>() {
    std::cout << "Heat Sink Removed" << std::endl;
}

template <class T>
T heatNode<T>::getCoolantLevel() const {
    return this->coolantLevel;
}

template <class T>
int heatNode<T>::getPower() const {
    return this->power;
}

#endif