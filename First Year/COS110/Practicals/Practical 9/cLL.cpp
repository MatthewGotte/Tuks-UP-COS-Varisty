#ifndef CLL_CPP
#define CLL_CPP

#include "cLL.h"
#include "citem.cpp"
#include <iostream>


template <class T>
cLL<T>::cLL() {
    this->head = nullptr;
    this->size = 0;
}

template <class T>
cLL<T>::~cLL() {
    if (!head) {
        return;
    }

    citem<T> * nodePtr = head;
    head = head->next;
    size--;

    citem<T> * deleteNode;
    for (int i = 0; i < size; i++) {
        deleteNode = head;
        head = head->next;
        delete deleteNode;
    }

    delete nodePtr;
}

template <class T>
bool cLL<T>::isEmpty() {
    if (this->head == nullptr) {
        return true;
    }
    return false;
}

template <class T>
int cLL<T>::getSize() {
    return this->size;
}

template <class T>
void cLL<T>::push(citem<T> *newItem) {
    T max;
    citem<T> * nodePtr;
    if (head) {
        nodePtr = head;
        max = nodePtr->getData();
        for (int i = 0; i < this->size; i++) {
            if (nodePtr->getData() > max) {
                max = nodePtr->getData();
            }
            nodePtr = nodePtr->next;
        }

        if (newItem->getData() > max) {
            //Insert in front
            nodePtr = head;
            while (nodePtr->next != head) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newItem;
            newItem->next = head;
            head = newItem;
        }
        else {
            //Add at back
            nodePtr = head;
            while (nodePtr->next != head) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newItem;
            newItem->next = head;
        }
    }
    else {
        head = newItem;
        newItem->next = head;
    }
    size++;
}

template <class T>
citem<T> * cLL<T>::pop() {
    if (head) {
        if (this->size > 1) {
            citem<T> * nodePtr;
            nodePtr = head->next;
            while(nodePtr->next != head) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = head->next;
            nodePtr = head;
            head = nodePtr->next;
            this->size--;
            if (this->size == 0) {
                head = nullptr;
            }
            return nodePtr;
        }
        else {
            citem<T> * nodePtr = head;
            head = nullptr;
            this->size--;
            return nodePtr;
        }
    }
    return 0;
}

template <class T>
citem<T> * cLL<T>::removeAt(T x) {
    if (this->head) {
        if (this->size != 0){
            citem<T> * nodePtr;
            nodePtr = head;
            for (int i = 0; i < this->size; i++) {
                if (nodePtr->getData() == x) {
                    return nodePtr;
                }
                else {
                    nodePtr = nodePtr->next;
                }
            }
        }
    }
    return 0;
}

template <class T>
void cLL<T>::printList() {
    if (this->head) {
        if (this->size != 0) {
            citem<T> * nodePtr;
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