#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack stack = Stack();

    cout << "Push a node:10"
         << "\n";
    stack.push(10);

    cout << "Push a node:20"
         << "\n";
    stack.push(20);
    cout << "Push a node:30"
         << "\n";
    stack.push(30);
    cout << "First node in the stack:" << stack.peakTop() << "\n";
    cout << "Pop a node...\n";
    stack.pop();
    cout << "First node in the stack:" << stack.peakTop() << "\n";

    cout << "Stack size:" << stack.getSize() << "\n";
    cout << "Is stack empty:" << stack.isEmpty() << "\n";

    return 0;
}
