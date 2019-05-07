#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    DoubleLinkedList list = DoubleLinkedList();
    list.addToTail(30);
    list.addToHead(20);
    list.addToHead(10);
    list.print();
    list.reverse();
    list.print();
    list.removeFromHead();
    list.print();
    list.removeFromTail();
    list.print();

    return 0;
}
