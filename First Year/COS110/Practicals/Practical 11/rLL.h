#ifndef RLL_H
#define RLL_H

#include "item.h"

template <class T>
class rLL {

private:
    item<T> * head;
    int size;
public:
    rLL();
    ~rLL();
    item<T> * getHead();
    void push(item<T> * newItem);
    item<T> * pop();
    int getSize();
    void recursivePrint(item<T> * c);
    void recursiveDelete(item<T> * node);
    void recursiveAltPrinting(item<T> * node, bool odd);
    item<T> * deleteAt(item<T> * node, int k);
    item<T> * determineMiddle(item<T> * node);
    void midpointRecursion(item<T> * t, int * n, item<T> ** midpoint);

};

#endif