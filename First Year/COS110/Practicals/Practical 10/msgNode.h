#ifndef MSGNODE_H
#define MSGNODE_H

template <class T>
class msgNode {

private:
    T message;
    int size;

public:
    msgNode * next;

    msgNode(T i, int s);
    ~msgNode();
    T getMessage() const;
    int getSize() const;

};

#endif