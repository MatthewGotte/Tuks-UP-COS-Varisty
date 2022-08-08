#ifndef DLL_CPP
#define DLL_CPP
#include "dLL.h"
#include "ditem.cpp"
#include <iostream>

template <class T>
dLL<T>::dLL() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <class T>
dLL<T>::~dLL() {
    ditem<T> * nodePtr;
    nodePtr = head;
    while(nodePtr) {
        head = nodePtr->next;
        delete nodePtr;
        nodePtr = head;
    }
}

template <class T>
ditem<T> * dLL<T>::getHead() {
    return this->head;
}

template <class T>
ditem<T> * dLL<T>::getTail() {
    return this->tail;
}

template <class T>
void dLL<T>::push(ditem<T> *newItem) {
    if (!head) {
        head = newItem;
        tail = newItem;
    }
    else {
        if (newItem->getData() < minNode()) {
            //Add to front
            newItem->next = head;
            newItem->prev = newItem;
            head = newItem;
        }
        else {
            //Add to back
            newItem->prev = tail;
            tail->next = newItem;
            tail = newItem;
        }
    }
    size++;
}

template <class T>
ditem<T> * dLL<T>::pop() {
    if (head) {
        ditem<T> * nodePtr = head;
        if (size == 1) {
            head = nullptr;
            nodePtr->next = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        size--;
        return nodePtr;
    }
    return 0;
}

template <class T>
ditem<T> * dLL<T>::getItem(int i) {
    if ((0 <= i) && (i < size)) {
        if (this->size != 0) {
            ditem<T> * nodePtr;
            nodePtr = head;
            for (int j = 0; j < i; j++) {
                nodePtr = nodePtr->next;
            }
            return nodePtr;
        }
    }
    return 0;
}

template <class T>
T dLL<T>::minNode() {
    ditem<T> * nodePtr;
    nodePtr = head;
    T min = nodePtr->getData();
    while (nodePtr->next) {
        nodePtr = nodePtr->next;
        if (nodePtr->getData() < min) {
            min = nodePtr->getData();
        }
    }
    return min;
}

template <class T>
int dLL<T>::getSize() {
    return this->size;
}

template <class T>
void dLL<T>::printList() {
    if (head) {
        if (this->size != 0) {
            ditem<T> * nodePtr;
            nodePtr = head;
            for (int i = 0; i < this->size; i++) {
                std::cout << nodePtr->getData();
                nodePtr = nodePtr->next;
                if (i < this->size - 1) {
                    std::cout << ",";
                }
            }
            std::cout << std::endl;
        }
    }
}

#endif