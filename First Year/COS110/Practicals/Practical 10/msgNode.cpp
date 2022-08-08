#ifndef MSGNODE_CPP
#define MSGNODE_CPP

#include "msgNode.h"

#include <iostream>

template <class T>
msgNode<T>::msgNode(T i, int s) {
    this->message = i;
    this->size = s;
    this->next = nullptr;
}

template <class T>
msgNode<T>::~msgNode() {
    std::cout << "Message Processed" << std::endl;
}

template <class T>
T msgNode<T>::getMessage() const {
    return this->message;
}

template <class T>
int msgNode<T>::getSize() const {
    return this->size;
}

#endif