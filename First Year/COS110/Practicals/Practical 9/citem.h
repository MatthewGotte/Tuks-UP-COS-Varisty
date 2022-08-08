#ifndef CITEM_H
#define CITEM_H

template <class T>
class citem {

private:
    T data;

public:
    citem(T t);
    ~citem();
    citem * next;
    T getData();

};

#endif