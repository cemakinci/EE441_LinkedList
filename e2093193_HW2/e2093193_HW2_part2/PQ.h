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
PriorityQueue<T>::PriorityQueue(void) // constructor
{}

template <class T>
int  PriorityQueue<T>::QEmpty(void) const //returns when the list is empty
{
    return Q.ListEmpty();
}


template <class T>
void PriorityQueue<T>::ShowQ() //prints out the queue
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


template <class T>
int  PriorityQueue<T>::QSize(void) const // returns the size of the queue
{
    return Q.ListSize();
}

template <class T>
T PriorityQueue<T>::QDelete(void)
{
if (Q.ListEmpty()) // if qlist is empty, terminate the program
{
cerr << "Calling QDelete for an empty queue!" << endl;
exit(1);

}
   return Q.DeleteFront(); //deletes the front member of the queue
}

  template <class T>
 PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& PQ)
{
  Q.CopyList(PQ); //copy the elements of the priority queue
}

template <class T>
void PriorityQueue<T>::QInsert(const T& item) // inserts an item to the priority queue according to the priority order
{
    if (Q.ListEmpty()) //if the qlist is empty insert an item to the front
    {
        Q.InsertFront(item);
    }
    else // if the list is not empty
    {
        Q.Reset();   // reset the position of the currentPtr

        while (!Q.EndOfList()) //until the end of the list, run the loop
        {
            if (item < Q.Data())  // found insertion point if item < current data
            {
                Q.InsertAt(item);
                break;
            }

            else if (item == Q.Data()) // found insertion point if item == current data
            {
                    Q.InsertAfter(item);
                break;
            }
            else   // if the item > current data go to the end of the list
            {
                Q.Next();
            }
        }
    }
    if (Q.EndOfList())  // add the current data to the end of the list
    {
        Q.InsertRear(item);
    }
}
template <class T>
PriorityQueue<T>::~PriorityQueue(void) // clear list for destruction
{
    Q.ClearList();
}
#endif  // PRIORITYQ_CLASS
