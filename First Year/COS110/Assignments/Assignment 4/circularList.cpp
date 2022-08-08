#include "circularList.h"

template <class T>
CircularList<T>::CircularList() {
    this->tail = nullptr;
}

template <class T>
CircularList<T>::CircularList(const CircularList<T> &other) {
    this->tail = nullptr;
    if (other.tail) {
        Node<T> * otherNode = other.tail;
        Node<T> * newNode = new Node<T>(otherNode->element);
        this->tail = newNode;

        otherNode = other.tail;
        otherNode = otherNode->next;
        Node<T> * prevNode = this->tail;

        while (otherNode->next != other.tail->next) {
            newNode = new Node<T>(otherNode->element);
            prevNode->next = newNode;
            prevNode = newNode;
            otherNode = otherNode->next;
        }
        newNode->next = this->tail;
    }
}

template <class T>
CircularList<T> & CircularList<T>::operator=(const CircularList<T> &other) {
    CircularList<T> * newList = new CircularList<T>();
    if (other.tail) {
        Node<T> * otherNode = other.tail;
        Node<T> * newNode = new Node<T>(otherNode->element);
        this->tail = newNode;

        otherNode = other.tail;
        otherNode = otherNode->next;
        Node<T> * prevNode = this->tail;

        while (otherNode->next != other.tail->next) {
            newNode = new Node<T>(otherNode->element);
            prevNode->next = newNode;
            prevNode = newNode;
            otherNode = otherNode->next;
        }
        newNode->next = this->tail;
    }

    return *newList;
}

template <class T>
CircularList<T> * CircularList<T>::clone() {
    CircularList<T> * newList = new CircularList<T>(*this);
    return newList;
}

template <class T>
CircularList<T>::~CircularList() {

}

template <class T>
void CircularList<T>::insert(int index, T element) {
    int s = size();
    if (!((0 <= index) && (index <= s))) {
        throw ("invalid index");
    }

    Node<T> * newNode = new Node<T>(element);
    Node<T> * nodePtr;

    if ((!tail) && (index == 0)) {
        tail = newNode;
        newNode->next = tail;
    }
    else if ((tail) && (index == 0)) {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    else if ((tail) && (index == s)) {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    else if (tail) {
        nodePtr = tail->next;//head
        for (int i = 0; i < index - 1; i++) {
            nodePtr = nodePtr->next;
        }
        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }
}

template <class T>
T CircularList<T>::remove(int index) {
    int s = size();
    if (!((0 <= index) && (index < s))) {
        throw ("empty structure");
    }

    Node<T> * nodePtr;
    Node<T> * prevPtr;

    if ((index == 0) && s == 1) {
        nodePtr = tail;
        this->tail = nullptr;
    }
    else if (index == 0) {
        nodePtr = tail->next;
        tail->next = nodePtr->next;
    }
    else {
        nodePtr = tail->next;
        for (int i = 0; i < index; i++) {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (index == size() - 1) {
            prevPtr->next = nodePtr->next;
            tail = prevPtr;
        }
        else {
            prevPtr->next = nodePtr->next;
        }
    }
    return nodePtr->element;
}

template <class T>
T CircularList<T>::get(int index) const {
    int s = size();
    if (!((0 <= index) && (index < s))) {
        throw ("empty structure");
    }
    Node<T> * nodePtr;
    if (index == 0) {
        nodePtr = tail->next;
    }
    else if (index == s) {
        nodePtr = tail;
    }
    else {
        nodePtr = tail->next;
        for (int i = 0; i < index; i++) {
            nodePtr = nodePtr->next;
        }
    }
    return nodePtr->element;
}

template <class T>
bool CircularList<T>::isEmpty() {
    if (!tail) {
        return true;
    }
    return false;
}

template <class T>
void CircularList<T>::clear() {
    if (!isEmpty()) {
        Node<T> * nodePtr = tail->next;
        while (nodePtr->next != tail) {
            nodePtr = tail->next;
            tail->next = nodePtr->next;
            //delete nodePtr;
        }
        tail = nullptr;
    }
}

template <class T>
ostream & CircularList<T>::print(ostream &os) {
    os << "[";
    if (this->tail) {
        Node<T> * nodePtr = tail->next;
        while (nodePtr) {
            if (nodePtr->next == tail->next) {
                os << nodePtr->element;
                break;
            }
            else {
                os << nodePtr->element;
                os << ",";
                nodePtr = nodePtr->next;
            }
        }
    }
    os << "]";
    return os;
}

template <class T>
ostream & operator<<(std::ostream& out, CircularList<T>& rhs) {
    return rhs.print(out);
}

template <class T>
int CircularList<T>::size() const {
    int numElements = 0;
    if (tail) {
        Node<T> * nodePtr = tail;
        numElements++;
        while (nodePtr->next != tail) {
            numElements++;
            nodePtr = nodePtr->next;
        }
    }
    return numElements;
}