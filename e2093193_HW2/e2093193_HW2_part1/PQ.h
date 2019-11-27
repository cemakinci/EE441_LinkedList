#ifndef PRIORITYQ_CLASS
#define PRIORITYQ_CLASS

#include "link.h"

template <class T>
class PriorityQueue
{
private:
    // assume T is a data type where > (greater than), < (less than) and == (equal to)
    // operators that allow comparison are defined and overloaded.
    LinkedList<T> Q;

public:
    // constructors
    PriorityQueue(void); // PROVIDED BELOW
    PriorityQueue(const PriorityQueue<T>& PQ); // Copy Constructor

    // destructor
    ~ PriorityQueue(void);

    int QSize(void) const;   // Returns the number of items stored in the Priority Queue
    int QEmpty(void) const; // PROVIDED BELOW

    void ShowQ(); // PROVIDED BELOW

    void QInsert(const T& item); // Inserts the item at the correct location in the Q List

    // Deletion methods
    T QDelete(void); // Deletes and returns the item with the highest priority

};

template <class T>
PriorityQueue<T>::PriorityQueue(void)
{}

template <class T>
int  PriorityQueue<T>::QEmpty(void) const
{
    return Q.ListEmpty();
}


template <class T>
void PriorityQueue<T>::ShowQ()
{
    for(Q.Reset(); !Q.EndOfList(); Q.Next())
        cout<<Q.Data()<<" ";
    cout<<"\n";
}



/***********************************/
/***********************************/
/* REST OF THE IMPLEMENTATION HERE */
/***********************************/
/***********************************/



#endif  // PRIORITYQ_CLASS
