#include <iostream>
#include <typeinfo>

#include "bin.h"

#include "train.h"

template<class T>
train<T>::train(int numBins) {
    this->bins = numBins;
    this->storage = new bin<T>*[numBins];
    for (int i = 0; i < this->bins; i++) {
        this->storage[i] = nullptr;
    }
}

template<class T>
train<T>::~train<T>() {
    for (int i = 0; i < this->bins; i++) {
        delete this->storage[i];
    }
    delete [] this->storage;
}

template<class T>
int train<T>::addBin(T item) {
    for (int i = 0; i < this->bins; i++) {
        if (this->storage[i] == nullptr) {
            this->storage[i] = new bin<T>(item);
            return i;
        }
    }
    return -1;
}

template<class T>
int train<T>::addBin(int index, T item) {
    if (this->storage[index] == nullptr) {
        this->storage[index] = new bin<T>(item);
        return index;
    }
    return -1;
}

template<class T>
int train<T>::removeBin(int index) {
    if ((0 <= index) && (index < this->bins) && (this->storage[index] != nullptr)) {
        delete this->storage[index];
        this->storage[index] = nullptr;
        return index;
    }
    return -1;
}

template<class T>
int train<T>::removeBin(int index, T type) {
    if (typeid(type) == typeid(T)) {
        if ((0 <= index) && (index < this->bins)) {
            delete this->storage[index];
            this->storage[index] = nullptr;
            return index;
        }
    }
    return -1;
}

template<class T>
void train<T>::printStorage() {
    for (int i = 0; i < this->bins; i++) {
        if (this->storage[i] != nullptr) {
            std::cout << "Bin " << i + 1 << ": " << this->storage[i]->getData() << std::endl;
        } else
            std::cout << "Bin " << i + 1 << ": NA" << std::endl;
    }
}

/*template int train<char>::addBin(char);
template void train<char>::printStorage();
template int train<char>::removeBin(int);
template train<char>::train(int);

template train<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::train(int);*/