#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list = LinkedList();

    cout << "Add node to head:10"
         << "\n";
    list.addToHead(10);
    cout << "Add node to tail:20"
         << "\n";
    list.addToTail(20);
    cout << "Add node to tail:30"
         << "\n";
    list.addToTail(30);
    cout << "Add node to tail:40"
         << "\n";
    list.addToTail(40);
    list.print();
    cout << "Reverse the list...\n";
    list.reverse();
    list.print();
    cout << "Remove node from head..."
         << "\n";
    list.print();
    cout << "Remove node from tail..."
         << "\n";
    list.print();
    cout << "List size:" << list.getSize()
         << "\n";
    cout << "Is list empty:" << list.isEmpty()
         << "\n";

    return 0;
}
