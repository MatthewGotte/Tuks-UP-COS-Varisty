#ifndef DITEM_H
#define DITEM_H

template <class T>
class ditem {

private:
    T data;

public:
    ditem(T t);
    ~ditem();
    ditem * next;
    ditem * prev;
    T getData();

};


#endif

