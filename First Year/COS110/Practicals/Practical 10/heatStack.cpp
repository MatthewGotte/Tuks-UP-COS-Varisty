#ifndef HEATSTACK_CPP
#define HEATSTACK_CPP

#include "heatStack.h"

#include "heatNode.h"
#include "heatNode.cpp"

template <class T>
heatStack<T>::heatStack() {
    this->top = nullptr;
}

template <class T>
heatStack<T>::~heatStack() {
    heatNode<T> * nodePtr = top;
    while (nodePtr) {
        if (nodePtr->next) {
            top = nodePtr->next;
            delete nodePtr;
        }
        else {
            delete nodePtr;
            top = nullptr;
        }
        nodePtr = top;
    }
}

template <class T>
void heatStack<T>::push(heatNode<T> *t) {
    if (this->top) {
        t->next = top;
        top = t;
    }
    else {
        this->top = t;
    }
}

template <class T>
void heatStack<T>::pop() {
    if (this->top) {
        if (this->top->next == nullptr) {
            //one element
            delete top;
            top = nullptr;
        }
        else {
            //many elements
            heatNode<T> * nodePtr;
            nodePtr = top;
            top = top->next;
            delete nodePtr;
        }
    }
    else {
        std::cout << "EMPTY" << std::endl;
    }
}

template <class T>
heatNode<T> * heatStack<T>::peek() {
    if (this->top == nullptr) {
        return 0;
    }

    return this->top;
}

template <class T>
void heatStack<T>::print() {
    heatNode<T> * nodePtr;
    nodePtr = top;
    while(nodePtr) {
        std::cout << "Heat Sink CL: " << nodePtr->getCoolantLevel() << std::endl;
        nodePtr = nodePtr->next;
    }
}

template <class T>
bool heatStack<T>::validateCooling(int *heat, int numSinks) {
    int sum = 0;
    //Condition 1:
    heatNode<T> * nodePtr;
    nodePtr = this->top;
    int x = 0;
    while (nodePtr) {
        x++;
        sum += nodePtr->getPower();
        nodePtr = nodePtr->next;
    }
    if (numSinks < x) { return false; }
    //std::cout << x << std::endl;

    //Condition 2:
    int array = 0;
    for (int i = 0; i < numSinks; i++) {
        array += heat[i];
    }
    if (array < sum) { return false; }

    //Condition 3:
    nodePtr = this->top;
    while (nodePtr) {
        if (nodePtr->getCoolantLevel() < x) { return false; }
        nodePtr = nodePtr->next;
    }

    return true;
}

#endif