#include <iostream>

#include "storage.h"
#include "storage.cpp"

#include "dLL.h"
#include "dLL.cpp"

#include "cLL.h"
#include "cLL.cpp"

using namespace std;

int main() {

    cout << "\nditem test: (constructor)\n";
    ditem<int> * a = new ditem<int>(5);
    ditem<int> * b = new ditem<int>(120);
    ditem<int> * c = new ditem<int>(125);
    ditem<int> * d = new ditem<int>(2);
    ditem<int> * e = new ditem<int>(115);
    cout << "Constructor succeeded" << endl << endl;

    cout << "dLL test: (constructor)\n";
    dLL<int> dList;
    cout << "Declaration succeeded\n\n";

    ///////////
    cout << "pop before adding\n";
    dList.pop();
    cout << "pop succeeded\n\n";
    //////////

    cout << "Adding items: (push)\n";
    dList.push(a);
    cout << "Added: \t" << a->getData() << endl;
    dList.push(b);
    cout << "Added: \t" << b->getData() << endl;
    dList.push(c);
    cout << "Added: \t" << c->getData() << endl;
    dList.push(d);
    cout << "Added: \t" << d->getData() << endl;
    dList.push(e);
    cout << "Added: \t" << e->getData() << endl;
    cout << "Adding succeeded\n";

    cout << "\nPrint: (printList) = '2,5,120,125,115'\n";
    dList.printList();
    cout << "Print succeeded\n\n";

    cout << "Get head: (getHead)\n";
    cout << "Output:\t" << dList.getHead() << endl << endl;

    cout << "Get tail: (getTail)\n";
    cout << "Output:\t" << dList.getTail() << endl << endl;

    cout << "Min node: (minNode)\n";
    cout << "min(2) = " << dList.minNode() << endl << endl;

    cout << "Size: (getSize)\n";
    cout << "size(5) = " << dList.getSize() << endl << endl;

    cout << "getAt: (125)\n";
    cout << dList.getItem(3)->getData() << endl;
    cout << "getAt succeeded\n\n";

    cout << "Pop:\n";
    cout << "Current = ";
    dList.printList();
    cout << "Size(5) = " << dList.getSize() << endl;
    dList.pop();
    cout << "Current = ";
    dList.printList();
    cout << "Size(4) = " << dList.getSize() << endl;
    dList.pop();
    cout << "Current = ";
    dList.printList();
    cout << "Size(3) = " << dList.getSize() << endl;
    dList.pop();
    cout << "Current = ";
    dList.printList();
    cout << "Size(2) = " << dList.getSize() << endl;

    cout << "Pop succeeded\n\n";

    cout << "Size: (getSize)\n";
    cout << "size(2) = " << dList.getSize() << endl << endl;

    cout << "Deleting Items (~ from dLL and ditem)\n";

    cout << "\n--------------------------------------------" << endl;

    cout << "\ncitem test: (constructor)\n";
    citem<int> * f = new citem<int>(5);
    citem<int> * g = new citem<int>(120);
    citem<int> * h = new citem<int>(125);
    citem<int> * i = new citem<int>(2);
    citem<int> * j = new citem<int>(115);
    cout << "Constructor succeeded" << endl << endl;

    cout << "cLL test: (constructor)\n";
    cLL<int> cList;
    cout << "Declaration succeeded\n\n";

    ///////////
    cout << "pop before adding\n";
    cList.pop();
    cout << "pop succeeded\n\n";
    //////////

    cout << "Empty: (isEmpty) = 'Empty'\n";
    if (cList.isEmpty()) {cout << "Empty\n";}
    else cout << "->VALUE ERROR HERE<-" << endl;
    cout << "Empty succeeded\n\n";

    cout << "Adding items: (push)\n";
    cList.push(f);
    cout << "Added: \t" << f->getData() << endl;
    cList.push(g);
    cout << "Added: \t" << g->getData() << endl;
    cList.push(h);
    cout << "Added: \t" << h->getData() << endl;
    cList.push(i);
    cout << "Added: \t" << i->getData() << endl;
    cList.push(j);
    cout << "Added: \t" << j->getData() << endl;
    cout << "Adding succeeded\n\n";

    cout << "Size: (getSize)\n";
    cout << "size(5) = " << cList.getSize() << endl << endl;

    cout << "Empty: (isEmpty) = 'Not Empty'\n";
    if (!cList.isEmpty()) {cout << "Not Empty\n";}
    else cout << "->VALUE ERROR HERE<-" << endl;
    cout << "Empty succeeded\n\n";

    cout << "Print: (printlist) = '125,120,5,2,115'\n";
    cList.printList();
    cout << "Print succeeded\n\n";

    cout << "Pop:\n";
    cout << "Current = ";
    cList.printList();
    cout << "Size(5) = " << cList.getSize() << endl;
    cList.pop();
    cout << "Current = ";
    cList.printList();
    cout << "Size(4) = " << cList.getSize() << endl;
    cList.pop();
    cout << "Current = ";
    cList.printList();
    cout << "Size(3) = " << cList.getSize() << endl;
    cList.pop();
    cout << "Current = ";
    cList.printList();
    cout << "Size(2) = " << cList.getSize() << endl;
    cList.pop();
    cout << "Current = ";
    cList.printList();
    cout << "Size(1) = " << cList.getSize() << endl;
    cList.pop();
    cout << "List should now be empty\n";
    cout << "Pop succeeded\n\n";

    cout << "Size: (getSize)\n";
    cout << "size(0) = " << cList.getSize() << endl << endl;

    cout << "Adding to pop blanked list:\n";
    cList.push(f);
    cout << "Added: \t" << f->getData() << endl;
    cList.push(g);
    cout << "Added: \t" << g->getData() << endl;
    cList.push(h);
    cout << "Added: \t" << h->getData() << endl;
    cout << "re-Addition succeeded\n";

    cout << "\n--------------------------------------------\n" << endl;

    cout << "store test: (constructor)\n";
    storage<int> str(15);
    cout << "Declaration succeeded\n\n";

    cout << "store Data: (storeData)\n";
    str.storeData(14);
    str.storeData(16);
    str.storeData(120);
    str.storeData(4);
    cout << "Even (cList) succeeded\n";
    str.storeData(15);
    str.storeData(133);
    str.storeData(21);
    str.storeData(3);
    cout << "Odd (dList) succeeded\n\n";

    cout << "store Printing: (printCList) = '120,16,14,4'\n";
    str.printCList();
    cout << "Print C succeeded\n\n";

    cout << "Storage Printing: (printDList) = '3,15,133,21'\n";
    str.printDList();
    cout << "Print D succeeded\n\n";

	return 0;
}