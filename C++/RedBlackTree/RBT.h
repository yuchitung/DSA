#include <queue>
#include "TreeNode.h"
using namespace std;

/** Red Black Tree **/
enum Color { RED, BLACK };
class RBT {
  private:
    TreeNode *root;
    TreeNode *neel;

  protected:
    void leftRotation(TreeNode *);
    void rightRotation(TreeNode *);
    void fixInsertion(TreeNode *);

  public:
    RBT() {
        neel = new TreeNode();
        neel->color = BLACK;
        root = neel;
        root->parent = neel;
    }
    
    void insertNode(int);
    TreeNode* insert(TreeNode *, TreeNode *);
    void deleteNode(int);
    void fixDeletion(TreeNode *);
    TreeNode *search(int);
    TreeNode *successor(TreeNode *);
    TreeNode *leftmost(TreeNode *);
    void inOrder();
    void levelOrder();
    void levelOrderHelper();
};

void RBT::leftRotation(TreeNode *node) {
    TreeNode *nodeRight = node->right;

    node->right = nodeRight->left;

    if (nodeRight->left != neel) {
        nodeRight->left->parent = node;
    }
    nodeRight->parent = node->parent;

    if (node->parent == neel) {
        root = nodeRight;
    } else if (node == node->parent->left) {
        node->parent->left = nodeRight;
    } else {
        node->parent->right = nodeRight;
    }
    nodeRight->left = node;
    node->parent = nodeRight;
}

void RBT::rightRotation(TreeNode *node) {
    TreeNode *nodeLeft = node->left;

    node->left = nodeLeft->right;

    if (nodeLeft->right != neel) {
        nodeLeft->right->parent = node;
    }

    nodeLeft->parent = node->parent;

    if (node->parent == neel) {
        root = nodeLeft;
    } else if (node == node->parent->left) {
        node->parent->left = nodeLeft;
    } else {
        node->parent->right = nodeLeft;
    }
    nodeLeft->right = node;
    node->parent = nodeLeft;
}

void RBT::insertNode(int data) {
    TreeNode *node = new TreeNode(data);
    node->left = neel;
    node->right = neel;
    node->parent = neel;

    root = insert(root, node);
    fixInsertion(node);
}

TreeNode* RBT::insert(TreeNode *current, TreeNode *newNode) {
    if (current == neel) {
        return newNode;
    }

    if (newNode->data < current->data) {
        current->left = insert(current->left, newNode);
        current->left->parent = current;
    } else if (newNode->data > current->data) {
        current->right = insert(current->right, newNode);
        current->right->parent = current;
    }

    return current;
}

void RBT::fixInsertion(TreeNode *current) {
    while ((current != root) && (current->color != BLACK) && (current->parent->color == RED)) {

        /* Case : Parent is the left child of grandparent */
        if (current->parent == current->parent->parent->left) {

            TreeNode *uncle = current->parent->parent->right;

            /* Case 1: Uncle is red */
            if (uncle != neel && uncle->color == RED) {
                current->parent->parent->color = RED;
                current->parent->color = BLACK;
                uncle->color = BLACK;
                current = current->parent->parent;
            }

            else {
                /* Case 2: Uncle is black and current node is the right child of
                 * its parent */
                if (current == current->parent->right) {

                    current = current->parent;
                    leftRotation(current);
                }

                /* Case 3: Uncle is black and current node is the left child of
                 * its parent */
                current->parent->color = BLACK;
                current->parent->parent->color = RED;
                rightRotation(current->parent->parent);
            }
        }

        /* Case : Parent is the right child of grandparent */
        else {
            TreeNode *uncle = current->parent->parent->left;

            /* Case 1: Uncle is red */
            if ((uncle != neel) && (uncle->color == RED)) {
                current->parent->parent->color = RED;
                current->parent->color = BLACK;
                uncle->color = BLACK;
                current = current->parent->parent;
            } else {
                /* Case 2: Uncle is black and current node is the left child of
                 * its parent */
                if (current == current->parent->left) {

                    current = current->parent;
                    rightRotation(current);
                }

                /* Case 3: Uncle is black and current node is the right child of
                 * its parent */
                current->parent->color = BLACK;
                current->parent->parent->color = RED;
                leftRotation(current->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void RBT::deleteNode(int key) {
    TreeNode *targetNode = search(key);
    if (targetNode == NULL) {
        cout << "Data not found."<<endl;
        return;
    }

    TreeNode *deleteNode = neel;
    TreeNode *childOfDeleteNode = neel;

    if (targetNode->left == neel || targetNode->right == neel) {
        deleteNode = targetNode;
    } else {
        /** If the target node has both left child and right child, find the
         * successor **/
        deleteNode = successor(targetNode);
    }
  
    /** Set childOfDeleteNode, it could be a real node or neel **/
    if (deleteNode->left != neel) {
        childOfDeleteNode = deleteNode->left;
    } else {
        childOfDeleteNode = deleteNode->right;
    }
    childOfDeleteNode->parent = deleteNode->parent;
    
    if (deleteNode->parent == neel) {
        root = childOfDeleteNode;
    } else if (deleteNode == deleteNode->parent->left) {
        deleteNode->parent->left = childOfDeleteNode;
    } else {
        deleteNode->parent->right = childOfDeleteNode;
    }

    if (deleteNode != targetNode) {
        targetNode->data = deleteNode->data;
    }

    /** If the deleted node is black, we need to fix RBT **/
    if (deleteNode->color == BLACK) {
        fixDeletion(childOfDeleteNode);
    }
}

void RBT::fixDeletion(TreeNode *current) {
    while (current != root && current->color == BLACK) {
        /** Case: If current is the left child of its parent **/
        if (current == current->parent->left) {
            TreeNode *sibling = current->parent->right;
            /** Case 1: If the sibling is red **/
            if (sibling->color == RED) {
                sibling->color = BLACK;
                current->parent->color = RED;
                leftRotation(current->parent);
                sibling = current->parent->right;
            }

            /** Case 2: If both children of the sibling are black **/
            if (sibling->left->color == BLACK &&
                sibling->right->color == BLACK) {
                sibling->color = RED;
                current = current->parent;
            } else {
                /** Case 3: The RIGHT child of the sibling is BLACK and LEFT
                 * child of the sibling is RED **/
                if (sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rightRotation(sibling);
                    sibling = current->parent->right;
                }

                /** Case 4: The RIGHT child of the sibling is RED and LEFT child
                 * of the sibling is BLACK **/
                sibling->color = current->parent->color;
                current->parent->color = BLACK;
                sibling->right->color = BLACK;
                leftRotation(current->parent);
                current = root;
            }
        }

        /** Case: If current is the right child of its parent **/
        else {
            TreeNode *sibling = current->parent->left;
            /** Case 1: If the sibling is red **/
            if (sibling->color == RED) {
                sibling->color = BLACK;
                current->parent->color = RED;
                rightRotation(current->parent);
                sibling = current->parent->left;
            }

            /** Case 2: If both children of the sibling are black **/
            if (sibling->left->color == BLACK &&
                sibling->right->color == BLACK) {
                sibling->color = RED;
                current = current->parent;
            }

            else {
                /** Case 3: The LEFT child of the sibling is BLACK and RIGHT
                 * child of the sibling is RED **/
                if (sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    leftRotation(sibling);
                    sibling = current->parent->left;
                }

                /** Case 4: The LEFT child of the sibling is RED and RIGHT child
                 * of the sibling is BLACK **/
                sibling->color = current->parent->color;
                current->parent->color = BLACK;
                sibling->left->color = BLACK;
                rightRotation(current->parent);
                current = root;
            }
        }
    }
    current->color = BLACK;
}

TreeNode* RBT::search(int key) {
    TreeNode *current = root;
    while (current != NULL && key != current->data) {

        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

TreeNode* RBT::leftmost(TreeNode *current) {
    while (current->left != neel) {
        current = current->left;
    }
    return current;
}

TreeNode* RBT::successor(TreeNode *current) {
    if (current->right != neel) {
        return leftmost(current->right);
    }
    TreeNode *newNode = current->parent;

    while (newNode != neel && current == newNode->right) {
        current = newNode;
        newNode = newNode->parent;
    }

    return newNode;
}

void inOrderHelper(TreeNode *root, TreeNode *neel) {
    if (root == neel){
        return;
    }

    inOrderHelper(root->left, neel);
    cout << root->data << " ";
    inOrderHelper(root->right, neel);
}

void RBT::levelOrderHelper() {
    if (root == neel) {
        return;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode *current = queue.front();
        cout << current->data << " ";
        queue.pop();

        if (current->left != neel)
            queue.push(current->left);

        if (current->right != neel)
            queue.push(current->right);
    }
}

void RBT::inOrder() { inOrderHelper(root, neel); }
void RBT::levelOrder() { levelOrderHelper(); }

