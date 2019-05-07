#include "TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree {
  public:
    TreeNode *root = NULL;

    TreeNode* insert(TreeNode *current, int value) {
        if (current == NULL) {
            return new TreeNode(value);
        }

        if (value < current->value) {
            current->left = insert(current->left, value);
        } else if (value > current->value) {
            current->right = insert(current->right, value);
        }
        return current;
    }

    TreeNode* search(TreeNode *current, int value) {
        if (current == NULL || current->value == value) {
            return current;
        }
        if (value < current->value) {
            return search(current->left, value);
        } else {
            return search(current->right, value);
        }
    }

    TreeNode* deleteNode(TreeNode *current, int value) {
        if (current == NULL) {
            return current;
        }

        /* Search recursively until the target node is found and deleted */
        if (value < current->value) {
            current->left = deleteNode(current->left, value);
            return current;
        } else if (value > current->value) {
            current->right = deleteNode(current->right, value);
            return current;
        }

        /* Left subtree is empty */
        if (current->left == NULL) {
            TreeNode *temp = current->right;
            delete current;
            return temp;
            /* Right subtree is empty */
        } else if (current->right == NULL) {
            TreeNode *temp = current->left;
            delete current;
            return temp;
            /* Left and right subtrees both exist */
        } else {
            TreeNode *succParent = current->right;
            TreeNode *succ = current->right;

            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            succParent->left = succ->right;
            current->value = succ->value;
            delete succ;
            return current;
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
     * Level-Order Traversal
     * also known as breadth-first search (BFS)
     */
    void levelOrder(TreeNode *root) {
        std::queue<TreeNode *> queue;

        queue.push(root);
        TreeNode *current;
        while (!queue.empty()) {
            TreeNode *current = queue.front();
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
