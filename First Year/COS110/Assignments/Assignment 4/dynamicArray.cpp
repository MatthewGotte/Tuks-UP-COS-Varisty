#include "dynamicArray.h"

#include <iostream>

template <class T>
DynamicArray<T>::DynamicArray(int s) {
    if (s <= 0) {
        throw ("Invalid size provided");
    }

    size = s;
    numElements = 0;

    //Construct Array:
    elements = new T*[size];
    for (int i = 0; i < size; i++) {
        //elements[i] = new T();
        elements[i] = nullptr;
    }
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) {
    this->size = other.size;
    this->numElements = other.numElements;
    //Construct Array:
    this->elements = new T*[size];
    for (int i = 0; i < size; i++) {
        //elements[i] = new T(*other.elements[i]);
        this->elements[i] = new T();
        elements[i] = other.elements[i];
    }
}

template <class T>
DynamicArray<T> & DynamicArray<T>::operator=(const DynamicArray<T> &other) {
    this->size = other.size;
    this->numElements = other.numElements;

    //Copy Elements:
    this->elements = new T*[size];
    for (int i = 0; i < size; i++) {
        this->elements[i] = new T();
        this->elements[i] = other.elements[i];
    }
    return *this;
}

template <class T>
DynamicArray<T> * DynamicArray<T>::clone() {
    DynamicArray<T> * temp = new DynamicArray<T>(this->size);
    temp->elements = new T*[this->size];
    for (int i = 0; i < this->size; i++) {
        if (this->elements[i] != nullptr) {
            temp->elements[i] = new T(*this->elements[i]);
        }
        else {
            temp->elements[i] = nullptr;
        }
    }
    return temp;
}

template <class T>
DynamicArray<T>::~DynamicArray<T>() {

}

template <class T>
void DynamicArray<T>::insert(int index, T element) {

    /*if ((index + 1) > size) {
        resize((index + 1) - size);
    }

    if ((numElements + 1) > size) {
        resize(1);
    }
    //Check shift:
    if (this->elements[index] != nullptr) {
        //Shift up:
        for (int i = size - 1; i > index; i--) {
            /*delete elements[i];
            elements[i] = new T(*elements[i - 1]);///*
            if (elements[i - 1] != nullptr) {
                delete elements[i];
                elements[i] = new T(*elements[i - 1]);
            }
            else {
                elements[i] = nullptr;
            }
        }
    }

    //delete elements[index];
    this->elements[index] = new T(element);
    numElements++;*/

    if (index == size) {
        resize(1);
        elements[index] = new T(element);
        numElements++;
    }
    else if (index < size) {
        if (elements[index] == nullptr) {
            elements[index] = new T(element);
            numElements++;
        }
        else {
            resize(1);
            for (int i = size - 1; i >= index; i--) {
                elements[i] = elements[i - 1];
            }
            //delete elements[index];
            elements[index] = new T(element);
            numElements++;
        }
    }
    else if (index > size) {
        resize(index + this->size - 1);
        elements[index] = new T(element);
        numElements++;
    }


}

template <class T>
void DynamicArray<T>::resize(int howMuch) {
    //Create temp:
    T ** temp;
    temp = new T*[size];
    for (int i = 0; i < size; i++) {
        if (elements[i] != nullptr) {
            temp[i] = new T(*elements[i]);
        }
        else {
            temp[i] = nullptr;
        }
    }
    //Deallocate old:
    for (int i = 0; i < size; i++) {
        delete elements[i];
    }
    delete [] elements;
    //Reallocate new:
    size += howMuch; //New size
    //cout << "new Size: " << size << endl;
    elements = new T*[size];
    //Copy size - 1 from temp (old):
    for (int i = 0; i < size - howMuch; i++) {
        if (temp[i] != nullptr) {
            elements[i] = new T(*temp[i]);
        }
        else {
            elements[i] = nullptr;
        }
    }
    //Deallocate temp:
    for (int i = 0; i < size - howMuch; i++) {
        delete temp[i];
    }
    delete [] temp;
}

template <class T>
T DynamicArray<T>::remove(int index) {
    if (elements[index] == nullptr) {
        throw ("empty structure");
    }

    /*
    T * temp = new T(*elements[index]);
    for (int i = index; i < numElements - 2; i++) {
        elements[i] = elements[i + 1];
    }
    numElements--;
    delete elements[numElements - 1];
    return *temp;
    */
    T * temp = new T(*elements[index]);
    for (int i = index; i < size - 1; i++) {
        /*delete elements[i];
        elements[i] = nullptr;
        elements[i] = new T(*elements[i + 1]);*/
        if (elements[i + 1] != nullptr) {
            delete elements[i];
            elements[i] = new T(*elements[i + 1]);
        }
        else {
            elements[i] = nullptr;
        }
    }
    delete elements[size - 1];
    elements[size - 1] = nullptr;
    return *temp;
}

template <class T>
T DynamicArray<T>::get(int index) const {
    if (elements[index] == nullptr) {
        throw ("empty structure");
    }

    return *elements[index];
}

template <class T>
bool DynamicArray<T>::isEmpty() {
    for (int i = 0; i < size; i++) {
        if (elements[i] != nullptr) {
            return false;
        }
    }
    return true;
}

template <class T>
void DynamicArray<T>::clear() {
    for (int i = 0; i < size; i++) {
        numElements--;
        delete elements[i];
        elements[i] = nullptr;
    }
}

template <class T>
ostream & DynamicArray<T>::print(ostream &os) {
    os << "[";
    for (int i = 0; i < size; i++) {
        if (elements[i] != nullptr) {
            os << *elements[i];
        }
        else {
            os << "*";
        }
        if (i != size - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

template <class T>
ostream & operator<<(std::ostream& out, DynamicArray<T>& rhs) {
    return rhs.print(out);
}

