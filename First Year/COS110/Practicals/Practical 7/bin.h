#ifndef BIN_H
#define BIN_H

template<class T>
class bin {
private:
    T * item;
public:
    bin(T t);
    ~bin();
    T getData() const;
};

#endif