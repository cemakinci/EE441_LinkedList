#include <iostream>

#include "link.h"
#include "PQ.h"
using namespace std;

int main()
{
   PriorityQueue<int>MyQ;
    MyQ.QInsert(10);
    MyQ.QInsert(20);
    MyQ.QInsert(20);
    MyQ.QInsert(20);
    MyQ.QInsert(25);
    MyQ.QInsert(25);
    int most_important=MyQ.QDelete();
    cout<<most_important<<endl;
   MyQ.ShowQ();
}
