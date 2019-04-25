#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue queue = Queue();
    cout << "Push node:" << 10 << "\n";
    queue.push(10);
    cout << "Push node:" << 20 << "\n";
    queue.push(20);
    cout << "Push node:" << 30 << "\n";
    queue.push(30);
    queue.print();
    cout << "Pop node:" << queue.pop() << "\n";
    cout << "Queue size:" << queue.getSize() << "\n";
    cout << "Is queue empty:" << queue.isEmpty() << "\n";

    return 0;
}