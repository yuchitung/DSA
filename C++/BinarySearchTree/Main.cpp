#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

void search(BinarySearchTree bst, int value) {
    TreeNode *target = bst.search(bst.root, value);

    if (target != NULL) {
        cout << "Find the node!" << endl;
    } else {
        cout << "Node not found!" << endl;
    }
}

int main() {
    cout << "Buinding binary search tree..." << endl;
    BinarySearchTree bst = BinarySearchTree();
    bst.root = bst.insert(bst.root, 10);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 15);
    bst.insert(bst.root, 5);

    cout << "In-order traversal:";
    bst.inOrder(bst.root);
    cout << endl;
    cout << "Level-order traversal:";
    bst.levelOrder(bst.root);
    cout << endl << endl;

    cout << "search node : 5" << endl;
    search(bst, 5);
    cout << "search node : 8" << endl;
    search(bst, 8);
    cout << endl;

    cout << "Delete node: 10" << endl;
    bst.deleteNode(bst.root, 10);
    cout << "In-order traversal:";
    bst.inOrder(bst.root);
    cout << endl;
    cout << "Level-order traversal:";
    bst.levelOrder(bst.root);

    return 0;
}
