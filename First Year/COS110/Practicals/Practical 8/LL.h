#ifndef LL_H
#define LL_H

#include "item.h"

template <class T>
class LL {

private:
    item<T> * head;
    int size;
    int randomSeed;

public:
    LL(int rS);
    ~LL();

    item<T> * getHead() const;
    void addItem(item<T> * newItem);
    void randomShuffleList();
    void randomShuffleList(int i);
    item<T> * pop();
    item<T> * getItem(int i) const;
    T minNode();
    T maxNode();
    int getSize() const;
    void printList();

};

#endif