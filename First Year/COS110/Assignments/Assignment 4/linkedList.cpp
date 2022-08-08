#include "linkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
    if (other.head) {
        Node<T> * otherPtr = other.head;
        Node<T> * nodePtr = new Node<T>(otherPtr->element);
        this->head = nodePtr;

        otherPtr = otherPtr->next;
        while (otherPtr) {
            Node<T> * temp = new Node<T>(otherPtr->element);
            nodePtr->next = temp;
            nodePtr = temp;
            otherPtr = otherPtr->next;
        }
    }
    else {
        this->head = nullptr;
    }
}

template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> &other) {
    LinkedList<T> * newList = new LinkedList<T>();

    if (other.head) {
        Node<T> * otherPtr = other.head;
        Node<T> * nodePtr = new Node<T>(otherPtr->element);
        this->head = nodePtr;

        otherPtr = otherPtr->next;
        while (otherPtr) {
            Node<T> * temp = new Node<T>(otherPtr->element);
            nodePtr->next = temp;
            nodePtr = temp;
            otherPtr = otherPtr->next;
        }
    }

    return *newList;
}

template <class T>
LinkedList<T> * LinkedList<T>::clone() {
    LinkedList<T> * newList = new LinkedList<T>(*this);
    return newList;
}

template <class T>
LinkedList<T>::~LinkedList<T>() {
    if (this->head) {
        Node<T> * nodePtr = this->head;
        while (nodePtr->next) {
            nodePtr = head;
            head = nodePtr->next;
            //delete nodePtr;?
        }
        head = nullptr;
    }
}

template <class T>
void LinkedList<T>::insert(int index, T element) {
    int s = size();
    if (!((0 <= index) && (index <= s))) {
        throw ("invalid index");
    }
    Node<T> * newNode = new Node<T>(element);

    if ((index == 0) && (this->head)) {
        newNode->next = head;
        head = newNode;
    }
    else if ((index == 0) && (!this->head)) {
        head = newNode;
    }
    else if ((this->head)) {
        Node<T> * nodePtr = this->head;
        for (int i = 0; i < index - 1; i++) {
            nodePtr = nodePtr->next;
        }
        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }

}

template <class T>
T LinkedList<T>::remove(int index) {
    int s = size();

    if (isEmpty() || (!((0 <= index) && (index <= s)))) {
            throw ("empty structure");
    }

    Node<T> * nodePtr = this->head;
    if (index == 0) {
        head = head->next;
        return nodePtr->element;
    }
    else {
        Node<T> * prevPtr = this->head;
        nodePtr = nodePtr->next;
        for (int i = 0; i < index - 1; i++) {
            nodePtr = nodePtr->next;
            prevPtr = prevPtr->next;
        }
        prevPtr->next = nodePtr->next;
        return nodePtr->element;
    }
}

template <class T>
T LinkedList<T>::get(int index) const {
    int s = size();
    if ((!this->head) || (!((0 <= index) && (index <= s)))) {
        throw ("empty structure");
    }
    Node<T> * nodePtr = this->head;
    for (int i = 0; i < index; i++) {
        nodePtr = nodePtr->next;
    }
    return nodePtr->element;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    if (this->head) {
        return false;
    }
    return true;
}

template <class T>
void LinkedList<T>::clear() {
    if (this->head) {
        Node<T> * nodePtr = this->head;
        while (nodePtr->next) {
            nodePtr = this->head;
            head = nodePtr->next;
            //delete nodePtr;
        }
        this->head = nullptr;
    }
}

template <class T>
Node<T> * LinkedList<T>::getLeader() {
    return this->head;
}

template <class T>
ostream & LinkedList<T>::print(ostream &os) {
    //Print to os here:
    os << "[";
    if (this->head) {
        Node<T> * nodePtr = head;
        while (nodePtr) {
            os << nodePtr->element;
            if (nodePtr->next) {
                os << ",";
            }
            nodePtr = nodePtr->next;
        }
    }
    os << "]";
    return os;
}

template <class T>
ostream & operator<<(std::ostream& out, LinkedList<T> & rhs) {
    return rhs.print(out);
}

template <class T>
int LinkedList<T>::size() const {
    int elements = 0;
    if (this->head) {
        Node<T> * nodePtr = this->head;
        while (nodePtr->next) {
            elements++;
            nodePtr = nodePtr->next;
        }
        elements++;
    }
    return elements;
}