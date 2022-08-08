#include "priorityQueue.h"

template <class T>
PriorityQueue<T>::PriorityQueue(LinearStructure<T> *c) : Queue<T>(c) {
    this->front = 0;
    this->rear = 0;
    this->ascend = true;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &other) : Queue<T>(other.dataStructure) {
    this->front = other.front;
    this->rear = other.rear;
}

template <class T>
PriorityQueue<T> & PriorityQueue<T>::operator=(const PriorityQueue<T> &other) {
    PriorityQueue<T> * newQueue = new PriorityQueue<T>(this->dataStructure);
    return *newQueue;
}

template <class T>
PriorityQueue<T>::~PriorityQueue<T>() {

}

template <class T>
void PriorityQueue<T>::insert(T el) {
    if (!this->isEmpty()) {
        if (ascend) {
            if (this->rear == 1) {
                if (el > this->dataStructure->get(0)) {
                    this->dataStructure->insert(1, el);
                    this->rear++;
                }
                else {
                    this->dataStructure->insert(0, el);
                    this->rear++;
                }
            }
            else {
                for (int i = 0; i < this->rear; i++) {
                    //cout  << "VAL = " << i << endl;
                    if (el < this->dataStructure->get(i)) {
                        //cout << "RAN";
                        this->dataStructure->insert(i, el);
                        this->rear++;
                        return;
                    }
                }
                //cout << "HERE" << endl;
                this->dataStructure->insert(this->rear, el);
                this->rear++;
            }
        }
        else {

            if (this->rear == 1) {
                if (el < this->dataStructure->get(0)) {
                    this->dataStructure->insert(1, el);
                    this->rear++;
                }
                else {
                    this->dataStructure->insert(0, el);
                    this->rear++;
                }
            }
            else {
                if (this->rear == 1) {
                    if (el > this->dataStructure->get(0)) {
                        this->dataStructure->insert(1, el);
                        this->rear++;
                    }
                    else {
                        this->dataStructure->insert(0, el);
                        this->rear++;
                    }
                }
                else {
                    for (int i = 0; i < this->rear; i++) {
                        //cout  << "VAL = " << i << endl;
                        if (el > this->dataStructure->get(i)) {
                            //cout << "RAN";
                            this->dataStructure->insert(i, el);
                            this->rear++;
                            return;
                        }
                    }
                    //cout << "HERE" << endl;
                    this->dataStructure->insert(this->rear, el);
                    this->rear++;
                }
            }
        }
    }
    else {
        this->dataStructure->insert(0, el);
        this->rear++;
    }
}

template <class T>
void PriorityQueue<T>::reverse() {

    T * temp = new T[this->rear + 1];
    int tRear = this->rear;

    int counter = 0;
    while (!this->isEmpty()) {
        temp[counter] = this->remove();
        counter++;
    }

    Queue<T> * newQueue = new Queue<T>(this->getImplementation());
    while (!newQueue->isEmpty()) {
        newQueue->remove();
    }
    for (int i = tRear - 1; i >= 0; i--) {
        newQueue->insert(temp[i]);
    }
    this->dataStructure = newQueue->getImplementation();
    this->rear = tRear;

    this->ascend = !this->ascend;
}