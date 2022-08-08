#ifndef STORAGE_CPP
#define STORAGE_CPP
#include "storage.h"
#include <iostream>
#include <cstdlib>


template <class T>
storage<T>::storage(int rS) {
    this->cList = new cLL<T>();
    this->dList = new dLL<T>();
    this->randomSeed = rS;
    srand(rS);
}

template <class T>
storage<T>::~storage() {
    delete cList;
    delete dList;
}

template <class T>
void storage<T>::storeData(T data) {
    if (data % 2 == 0) {
        citem<T> * temp = new citem<T>(data);
        cList->push(temp);
    }
    else {
        ditem<T> * temp = new ditem<T>(data);
        dList->push(temp);
    }
}

template <class T>
void storage<T>::printCList() {
    cList->printList();
}

template <class T>
void storage<T>::printDList() {
    dList->printList();
}

#endif