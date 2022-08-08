//
// Created by DitFred on 10/29/2020.
//

#ifndef ASSIGNMENT_4_PRIORITYQUEUE_H
#define ASSIGNMENT_4_PRIORITYQUEUE_H


#include "queue.h"
#include "linearStructure.h"

template<class T>
class PriorityQueue : public Queue<T>
{
public:
    /*
    The constructor initializes the Container
    with the structure passed in as a parameter
    The elements added to the container must be
    stored in the object to which dataStructure
    points.
    */
    PriorityQueue(LinearStructure<T>* c);

    /*
    Copy constructor
    */
    PriorityQueue(const PriorityQueue<T>& other);

    /*
    Overloaded assignment operator.
    */
    virtual PriorityQueue<T>& operator=(const PriorityQueue<T>& other);

    /*
    Destructor.
    */
    virtual ~PriorityQueue();

    /*
    Inserts an element into the queue.  The elements in the queue
    remain sorted according to el at all times and should be inserted to maintain
    the order.  See the ascend flag for more information.
    */
    virtual void insert(T el);

    /*
    This function flips the ascend flag.  You will have
    to reverse the elements everytime this function is called.
    */
    virtual void reverse();

private:
    /*
    This flag determines whether the queue should be kept sorted
    in ascending order or descending order.  If the flag is true,
    then maintain an ascending sorted order, and if it is false,
    maintain a descending order.  It should be set to true
    in your constructor.
    */
    bool ascend;
};


#endif //ASSIGNMENT_4_PRIORITYQUEUE_H
