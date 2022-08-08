#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include "msgNode.h"

template <class T>
class msgQueue {

private:
    msgNode<T> * head;
    msgNode<T> * tail;

public:
    msgQueue();
    ~msgQueue();
    void enqueue(msgNode<T> * t);
    void dequeue();
    msgNode<T> * peek();
    void print();
    void compileMessageData();

};

#endif