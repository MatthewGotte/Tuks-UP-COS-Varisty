#include "queue.h"

template <class T>
Queue<T>::Queue(LinearStructure<T> *c) : OrderedContainer<T>(c) {
    this->front = 0;
    this->rear = 0;
}

template <class T>
Queue<T> & Queue<T>::operator=(const Queue<T> &other) {
    Queue<T> * newQueue = new Queue<T>(this->dataStructure);
    return *newQueue;
}

template <class T>
Queue<T>::Queue(const Queue<T> &other) : OrderedContainer<T>(other.dataStructure) {
    this->front = other.front;
    this->rear = other.rear;
}

template <class T>
Queue<T>::~Queue() {
    delete this->dataStructure;
    this->rear = 0;
    this->front = 0;
}

template <class T>
T Queue<T>::remove() {
    T ret = this->dataStructure->remove(0);
    this->front--;
    return ret;
}

template <class T>
T Queue<T>::next() {
    return this->dataStructure->get(0);
}

template <class T>
void Queue<T>::insert(T el) {
    this->dataStructure->insert(this->front, el);
    this->front++;
}

template <class T>
void Queue<T>::reverse() {

    T * temp = new T[this->front + 1];
    int tFront = this->front;

    int counter = 0;
    while (!this->isEmpty()) {
        temp[counter] = this->remove();
        counter++;
    }

    /*
    cout << "//////////" << endl;
    cout << "COPIED VALS = ";
    for (int i = 0; i < tFront; i++) {
        cout << temp[i] << "\t";
    }
    cout << endl;
    cout << "//////////" << endl;
     */

    Queue<T> * newQueue = new Queue<T>(this->getImplementation());
    newQueue->dataStructure->clear();
    for (int i = tFront - 1; i >= 0; i--) {
        newQueue->insert(temp[i]);
    }
    this->dataStructure = newQueue->getImplementation();
    this->front = tFront;

}