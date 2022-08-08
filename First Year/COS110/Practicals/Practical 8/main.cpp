#include "item.h"
#include "LL.h"
#include "LL.cpp"
#include <iostream>

using namespace std;

int main()
{

    LL<int> myList(9999);

    item<int> * myItemTest;
    myItemTest=myList.pop();
    cout<<"getting size should be 0\n";
    cout<<myItemTest<<"\n";
    cout<<"getting size should be 0\n";
    cout<<myList.getSize()<<"\n";
    item<int> * myItem99=nullptr;
    myList.addItem(myItem99);
    cout<<"getting size should be 0\n";
    cout<<myList.getSize()<<"\n";
    item<int> * myItem=new item<int>(5);
    item<int> * myItem2=new item<int>(10);
    item<int> * myItem3=new item<int>(20);
    item<int> * myItem4=new item<int>(30);

    item<int> * myItem5=new item<int>(3);
    item<int> * myItem6=new item<int>(2);
    myList.addItem(myItem);
    myList.addItem(myItem2);
    myList.addItem(myItem3);
    myList.addItem(myItem4);
    cout<<"getting size should be 4\n";
    cout<<myList.getSize()<<"\n";
    myList.addItem(myItem5);
    myList.addItem(myItem6);
    cout<<"getting size should be 6\n";
    cout<<myList.getSize()<<"\n";
    cout<<"==============printing before shuffle \n";
    myList.printList();
    myList.randomShuffleList();
    //cout<<"should now be 20 10 5 3 2 30\n";
    myList.printList();
    //cout<<"should now be 5 3 2 30 20 10\n";
    myList.randomShuffleList(2);
    myList.printList();
    cout<<"testing that 1 and 0 both give the head as start\t";
    myList.randomShuffleList(1);
    myList.printList();
    cout<<"testing that 1 and 0 both give the head as start\t";
    myList.randomShuffleList(0);
    myList.printList();
    cout<<"here is the max "<<myList.maxNode()<<"\n";

    myItem=myList.pop();
    cout<<"and returning the head which should be 5\n";
    cout<<myItem->getData()<<"\n";
    cout<<"deleting 5 \n";
    delete myItem;
    cout<<"getting size should be 5\n";
    cout<<myList.getSize()<<"\n";
    cout<<"========================testing unlimited popping========\n";
    myItem=myList.pop();
    myItem=myList.pop();
    myItem=myList.pop();
    myItem=myList.pop();
    myItem=myList.pop();
    myItem=myList.pop();
    myItem=myList.pop();
    myItem=myList.pop();


    //test part 2

    cout<<"testing shuffles \n";
    LL<int> mywList(55);
    item<int> * mywItem=new item<int>(5);
    item<int> * mywItem2=new item<int>(10);
    item<int> * mywItem3=new item<int>(20);
    item<int> * mywItem4=new item<int>(30);
    item<int> * mywItem5=new item<int>(40);
    mywList.addItem(mywItem);
    mywList.addItem(mywItem2);
    mywList.addItem(mywItem3);
    mywList.addItem(mywItem4);
    mywList.addItem(mywItem5);
    cout<<"list is\n";
    mywList.printList();
    mywList.randomShuffleList();

    cout<<"my new list is \n";
    mywList.printList();
    cout<<"calling random shuffle where i want the list to shuffle once and then chose index 3\n";
    mywList.randomShuffleList(3);
    mywList.printList();
    cout<<"testing links first the head is\n";
    mywItem5=mywList.getHead();
    cout<<mywItem5->getData();
    mywItem5=mywItem5->next;
    while(mywItem5!=nullptr)
    {

        cout<<"which points to "<<mywItem5->getData()<<"\n";
        mywItem5=mywItem5->next;

    }


    // in ll.cpp #include "LL.h" #include "item.cpp" in ll.h #include "item.h" in item.cpp #include "item.h" in main .cpp #include "item.h" #include "LL.h" #include "LL.cpp"

    return 0;
}
/*Get min
1
Get Max
9
Get size
5
Get item number 4
1
1 Deleted
Get size 2
4
9,6,4,3

List Print
6,5,4,3,2,1

1 Deleted

6,5,4,3,2

3
3 Deleted
0
3 Deleted
6 Deleted
5 Deleted
4 Deleted
3 Deleted
2 Deleted
9 Deleted
1 Deleted
6 Deleted
4 Deleted
3 Deleted
*/