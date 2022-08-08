#include "rLL.h"
#include "item.cpp"
#include <iostream>

using namespace std;

template <class T>
rLL<T>::rLL() {
    this->head = nullptr;
    this->size = 0;
}

template <class T>
rLL<T>::~rLL() {
    this->recursiveDelete(this->getHead());
}

template <class T>
item<T> * rLL<T>::getHead() {
    return this->head;
}

template <class T>
void rLL<T>::push(item<T> *newItem) {
    if (this->head) {
        newItem->next = head;
        head = newItem;
    }
    else {
        this->head = newItem;
    }
    this->size++;
}

template <class T>
item<T> * rLL<T>::pop() {
    item<T> * temp = head;
    head = head->next;
    this->size--;
    return temp;
}

template <class T>
int rLL<T>::getSize() {
    return this->size;
}

template <class T>
void rLL<T>::recursivePrint(item<T> *c) {
    if (head) {
        std::cout << c->getData();
        if (c->next) {
            std::cout << ",";
            recursivePrint(c->next);
        }
        else
            std::cout << std::endl;
    }
}

template <class T>
void rLL<T>::recursiveDelete(item<T> *node) {
    if (head) {
        if (node->next) {
            item<T> * temp = node->next;
            node->next = nullptr;
            recursiveDelete(temp);
        }
        else
            node->next = nullptr;
        this->size--;
    }
}

template <class T>
void rLL<T>::recursiveAltPrinting(item<T> *node, bool odd) {
    if (odd) {
        cout << node->getData();
        if (node->next) {
            if (node->next->next) {
                cout << ",";
                recursiveAltPrinting(node->next, !odd);
            }
            else
                cout << endl;
        }
        else
            cout << endl;
    }
    else {
        node = node->next;
        recursiveAltPrinting(node, !odd);
    }
}

template <class T>
item<T> * rLL<T>::deleteAt(item<T> *node, int k) {
    if (k < size) {
        if (k == 0) {
            if (head->next) {
                head = head->next;
                size--;
            }
            else {
                head = nullptr;
            }
            return node;
        }
        if (k == 1) {
            if (node->next) {
                if (node->next->next) {
                    node->next = node->next->next;
                    item<T> * temp = node->next;
                    size--;
                    return temp;
                }
                else {
                    item<T> * temp = node->next;
                    node->next = nullptr;
                    size--;
                    return temp;
                }
            }
        }
        else {
            deleteAt(node->next, k - 1);
        }
    }
    return node;
}

template <class T>
item<T> * rLL<T>::determineMiddle(item<T> *node) {
    int midNode = (size - 1)/2;
    item<T> * temp = node;
    for (int i = 0; i < midNode; i++) {
        temp = temp->next;
    }
    return temp;
}

template <class T>
void rLL<T>::midpointRecursion(item<T> *t, int *n, item<T> **midpoint) {

}