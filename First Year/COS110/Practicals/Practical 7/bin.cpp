#include "bin.h"
#include <string>

template<class T>
bin<T>::bin(T t) {
    this->item = new T(t);
}

template<class T>
bin<T>::~bin<T>() {
    delete this->item;
}

template<class T>
T bin<T>::getData() const {
    return *this->item;
}

template bin<int>::bin(int);
template int bin<int>::getData() const;
template bin<int>::~bin();

template bin<double>::bin(double);
template double bin<double>::getData() const;
template bin<double>::~bin();

template bin<std::string>::bin(std::string);
template std::string bin<std::string>::getData() const;
template bin<std::string>::~bin();