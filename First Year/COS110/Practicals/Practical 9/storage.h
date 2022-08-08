#ifndef STORAGE_H
#define STORAGE_H

#include "cLL.h"
#include "dLL.h"

template <class T>
class storage {

private:
    cLL<T> * cList;
    dLL<T> * dList;
    int randomSeed;

public:
    storage(int rS);
    ~storage();
    void storeData(T data);
    void printCList();
    void printDList();

};

#endif