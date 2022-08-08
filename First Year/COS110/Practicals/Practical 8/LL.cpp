#include "LL.h"
#include "item.cpp"

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
LL<T>::LL(int rS) {
    this->randomSeed = rS;
    this->head = nullptr;
    this->size = 0;
    srand(rS);
}

template <class T>
LL<T>::~LL() {
    while(head != nullptr) {
        item<T> * nodePtr;
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        this->size--;
    }
}

template <class T>
item<T> * LL<T>::getHead() const {
    return this->head;
}

template <class T>
void LL<T>::addItem(item<T> * newItem) {
    if (newItem == nullptr) {return;}
    newItem->next = nullptr;
    if (head == nullptr) {
        head = newItem;
    } else {
        if (newItem->getData() <= minNode()) {
            item<T> *nodePtr;
            nodePtr = head;
            while (nodePtr->next) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newItem;
        } else {
            newItem->next = head;
            head = newItem;
        }
    }
    size++;
}

template <class T>
void LL<T>::randomShuffleList() {
    if (this->head) {
        srand(this->randomSeed);
        int i = rand() % (this->size);
        //cout << "Random = " << i << endl;
        if (i != 0) {
            item<T> * node;
            item<T> * prev;
            item<T> * last;
            item<T> * first;
            node = getItem(i);
            prev = getItem(i - 1);
            last = getItem(this->size - 1);
            first = getItem(0);

            this->head = node;
            last->next = first;
            prev->next = nullptr;
        }
    }
}

template <class T>
void LL<T>::randomShuffleList(int i) {
    if (i != 0) {
        if ((0 <= i) && (i < this->size)) {
            item<T> * node;
            item<T> * prev;
            item<T> * last;
            item<T> * first;
            node = getItem(i);
            prev = getItem(i - 1);
            last = getItem(this->size - 1);
            first = getItem(0);

            this->head = node;
            last->next = first;
            prev->next = nullptr;
        }
    }
}

template <class T>
item<T> * LL<T>::pop() {
    if (this->head) {
        item<T> * nodePtr;
        nodePtr = this->head;
        this->head = nodePtr->next;
        //nodePtr->next = nullptr;
        this->size--;
        return nodePtr;
    }
    return 0;
}

template <class T>
T LL<T>::minNode() {
    if (this->head) {
        T lowest = head->getData();
        item<T> *nodePtr;
        nodePtr = this->head;
        while (nodePtr) {
            if (nodePtr->getData() < lowest) { lowest = nodePtr->getData(); }
            nodePtr = nodePtr->next;
        }
        return lowest;
    }
    return 0;
}

template <class T>
T LL<T>::maxNode() {
    if (this->head) {
        T highest = head->getData();
        item<T> *nodePtr;
        nodePtr = this->head;
        while (nodePtr) {
            if (nodePtr->getData() > highest) { highest = nodePtr->getData(); }
            nodePtr = nodePtr->next;
        }
        return highest;
    }
    return 0;
}

template <class T>
int LL<T>::getSize() const {
    return this->size;
}

template <class T>
item<T> * LL<T>::getItem(int i) const {
    if ((0 <= i) && (i < this->size)) {
        item<T> * nodePtr;
        nodePtr = this->head;
        for (int j = 0; j < i; j++) {
            nodePtr = nodePtr->next;
        }
        return nodePtr;
    }
    return 0;
}

template <class T>
void LL<T>::printList() {
    if (this->head) {
        item<T> *nodePtr;
        nodePtr = this->head;
        int i = 0;
        while (nodePtr) {
            cout << nodePtr->getData();
            nodePtr = nodePtr->next;
            if (i != this->size - 1) { cout << ","; }
            i++;
        }
        cout << endl;
    }
}