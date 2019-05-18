#include <iostream>
#include "RBT.h"
using namespace std;

int main() {
    RBT tree;

    cout << "Insert nodes:7,6,5,4,3,2,1"<<endl;
    tree.insertNode(7);
    tree.insertNode(6);
    tree.insertNode(5);
    tree.insertNode(4);
    tree.insertNode(3);
    tree.insertNode(2);
    tree.insertNode(1);

    cout << "Inoder Traversal of Created Tree"<<endl;
    tree.inOrder();

    cout <<endl<< "Level Order Traversal of Created Tree"<<endl;
    tree.levelOrder();

    cout <<endl<<endl<< "Delete node:2";
    tree.deleteNode(2);

    cout <<endl<< "Inoder Traversal of Created Tree"<<endl;
    tree.inOrder();

    cout <<endl<< "Level Order Traversal of Created Tree"<<endl;
    tree.levelOrder();
    return 0;
}
