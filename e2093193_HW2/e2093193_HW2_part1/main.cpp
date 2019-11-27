#include <iostream>
#include "node.h"
#include "link.h"
using namespace std;

int main()
{
    LinkedList<int> MyList;
    for(int i=1; i<6; i++)
        MyList.InsertAfter(i);
    for(MyList.Reset(); !MyList.EndOfList(); MyList.Next())
        cout<<MyList.Data()<<" ";
        cout<<endl;
    MyList.Reset(4);
    MyList.DeleteAt();
    MyList.InsertFront(9);
    MyList.InsertAt(18);
    for(MyList.Reset(); !MyList.EndOfList(); MyList.Next())
        cout<<MyList.Data()<<" ";
        cout<<endl;

}

