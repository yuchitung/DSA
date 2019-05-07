#include "TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

class BinaryTree {
  public:
    TreeNode *root = NULL;
    BinaryTree(int data[], int size) {
        int count = 1;
        TreeNode *node = new TreeNode(data[0]);
        TreeNode *current;
        std::queue<TreeNode *> queue;

        root = node;
        current = node;
        while (count != size) {
            TreeNode *leftNode = new TreeNode(data[count]);
            leftNode->parent = current;
            current->left = leftNode;
            queue.push(leftNode);
            count++;
            if (count == size) {
                break;
            }
            TreeNode *rightNode = new TreeNode(data[count]);
            rightNode->parent = current;
            current->right = rightNode;
            queue.push(rightNode);
            count++;
            current = queue.front();
            queue.pop();
        }
    }

    /**
     * Pre-Order Traversal (NLR)
     * also known as depth-first search (DFS)
     */
    void preOrder(TreeNode *current) {
        if (current) {
            cout << current->value << " ";
            preOrder(current->left);
            preOrder(current->right);
        }
    }

    /**
     * In-Order Traversal (LNR)
     */
    void inOrder(TreeNode *current) {
        if (current) {
            inOrder(current->left);
            cout << current->value << " ";
            inOrder(current->right);
        }
    }

    /**
     * Post-Order Traversal (LRN)
     */
    void postOrder(TreeNode *current) {
        if (current) {
            postOrder(current->left);
            postOrder(current->right);
            cout << current->value << " ";
        }
    }

    /**
     * Level-Order Traversal
     * also known as breadth-first search (BFS)
     */
    void levelOrder(TreeNode *current) {
        std::queue<TreeNode *> queue;
        queue.push(current);
        while (!queue.empty()) {
            current = queue.front();
            queue.pop();
            cout << current->value << " ";
            if (current->left != NULL) {
                queue.push(current->left);
            }
            if (current->right != NULL) {
                queue.push(current->right);
            }
        }
    }
};
