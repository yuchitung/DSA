#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(data) / sizeof(data[0]);
    cout << "Create a binary tree with data:";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";

    BinaryTree binaryTree = BinaryTree(data, size);
    cout << "\n";

    cout << "Pre-Order traversal:";
    binaryTree.preOrder(binaryTree.root);
    cout << "\n";

    cout << "In-Order traversal:";
    binaryTree.inOrder(binaryTree.root);
    cout << "\n";

    cout << "Post-Order traversal:";
    binaryTree.postOrder(binaryTree.root);
    cout << "\n";

    cout << "Level-Order traversal:";
    binaryTree.levelOrder(binaryTree.root);
    cout << "\n";

    return 0;
}
