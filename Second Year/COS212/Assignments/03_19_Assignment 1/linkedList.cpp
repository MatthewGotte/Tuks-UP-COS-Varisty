#include "linkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

//Clone
template <class T>
LinkedList<T> & LinkedList<T>::clone() {

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {

}

template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> &other) {

}

template <class T>
LinkedList<T>::~LinkedList() {

}

template <class T>
void LinkedList<T>::insert(int index, T element) {
    if ((0 <= index) && (index <= size())) {
        if (index == 0) {
            Node<T> * temp = new Node<T>(index, head);
            head = temp;
        } else if (index == size()) {
            Node<T> * nodePrt = head;
            while (nodePrt->next) {
                nodePrt = nodePrt->next;
            }
            Node<T> * temp = new Node<T>(element);
            nodePrt->next = temp;
        }
        else {
            Node<T> * nodePtr = head;
            for (int i = 0; i < index; i++) {
                nodePtr = nodePtr->next;
            }
            Node<T> * temp = new Node<T>(element, nodePtr->next);
            nodePtr->next = temp;
        }
    }
}

template <class T>
T LinkedList<T>::remove(int index) {
    if (!((0 <= index) && (index < size())) || size() == 0) {
        throw "empty structure";
    }

    Node<T> * nodePtr = head;
    if (size() == 1) {
        delete nodePtr;
        this->head = nullptr;
    } else {
        Node<T> * nextPtr = head->next;
        for (int i = 0; i < index; i++) {
            nodePtr = nextPtr;
            nextPtr = nextPtr->next;
        }
        nodePtr = nextPtr->next;
        delete nextPtr;
    }
}

template <class T>
bool LinkedList<T>::isEmpty() {
    if (this->head) {
        return true;
    }
    return false;
}

template <class T>
void LinkedList<T>::clear() {
    if(this->head) {
        Node<T> * nodePtr = head;
        if (size() == 1) {
            delete nodePtr;
        }
        else {
            Node<T> * nextPtr = nodePtr->next;
            while (nextPtr->next) {
                delete nodePtr;
                nodePtr = nextPtr;
                nextPtr = nextPtr->next;
            }
            delete nodePtr;
            delete nextPtr;
        }
        this->head = nullptr;
    }
}

template <class T>
Node<T> * LinkedList<T>::getLeader() {
    return head;
}

//Protected:
template <class T>
ostream & LinkedList<T>::print(ostream &os) {

}

//Private:
template <class T>
int LinkedList<T>::size() {
    if (this->head) {
        int noNodes = 0;
        Node<T> * nodePtr = this->head;
        while (nodePtr->next) {
            noNodes++;
            nodePtr = nodePtr->next;
        }
        return noNodes;
    }
    return 0;
}