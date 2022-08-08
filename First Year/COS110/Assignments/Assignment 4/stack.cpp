#include "stack.h"

template <class T>
Stack<T>::Stack(LinearStructure<T> *c) : OrderedContainer<T>(c) {
    this->stackTop = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T> &other) : OrderedContainer<T>(other.dataStructure) {
    this->stackTop = other.stackTop;
}

template <class T>
Stack<T> & Stack<T>::operator=(const Stack<T> &other) {
    Stack<T> * newStack = new Stack<T>(this->dataStructure);
    return *newStack;
}

template <class T>
Stack<T>::~Stack() {
    delete this->dataStructure;
}

template <class T>
T Stack<T>::remove() {
    stackTop--;
    T ret = this->dataStructure->remove(this->stackTop);
    return ret;
}

template <class T>
T Stack<T>::next() {
    return this->dataStructure->get(--this->stackTop);
}

template <class T>
void Stack<T>::insert(T el) {
    this->dataStructure->insert(this->stackTop, el);
    this->stackTop++;
}

template <class T>
void Stack<T>::reverse() {
    T * temp = new T[stackTop + 1];
    int tTop = stackTop;

    int counter = 0;
    while(!this->isEmpty()) {
        temp[counter] = this->remove();
        counter++;
    }

    Stack<T> * newStack = new Stack<T>(this->getImplementation());
    newStack->dataStructure->clear();
    for (int i = 0; i < tTop; i++) {
        newStack->insert(temp[i]);
    }
    this->dataStructure = newStack->getImplementation();
    stackTop = tTop;

}