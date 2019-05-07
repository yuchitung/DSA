#include "Node.h"
#include <iostream>

using namespace std;

class Queue {
  private:
    int size = 0;
    Node *head, *tail;

  public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void push(int value) {
        Node *node = new Node(value);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }

        size++;
    }

    int pop() {
        int value = head->value;
        head = head->next;
        size--;
        return value;
    }

    void print() {
        cout << "Print current queue:";
        Node *current = head;

        if (head == NULL) {
            return;
        }

        if (head == tail) {
            cout << head->value;
            cout << "\n";
            return;
        }

        while (current != NULL) {
            if (current != tail) {
                cout << current->value << "->";
            } else {
                cout << current->value;
            }
            current = current->next;
        }
        cout << "\n";
        delete current;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        } else {
            return false;
        }
    }

    int getSize() { return size; }
};
