#ifndef HEATNODE_H
#define HEATNODE_H

template <class T>
class heatNode {

private:
    T coolantLevel;
    //heatNode<T> * next;
    int power;

public:
    heatNode<T> * next;

    heatNode(T i, int p);
    ~heatNode();
    T getCoolantLevel() const;
    int getPower() const;

};

#endif