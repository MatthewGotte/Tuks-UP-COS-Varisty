#include <iostream>
#include "rLL.h"
#include "rLL.cpp"
#include "item.h"

using namespace std;

int main() {
    rLL<int> x;
    item<int> * a = new item<int>(1);
    item<int> * b = new item<int>(2);
    item<int> * c = new item<int>(3);
    item<int> * d = new item<int>(4);
    item<int> * e = new item<int>(5);
    item<int> * f = new item<int>(6);
    item<int> * g = new item<int>(7);

    x.push(a);
    x.push(b);
    x.push(c);
    x.push(d);
    x.push(e);
    x.push(f);
    x.push(g);

    x.recursivePrint(x.getHead());
    cout << x.determineMiddle(x.getHead())->getData() << endl;

    return 0;
}