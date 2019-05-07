#include "Node.h"
#include <iostream>
using namespace std;
class DoubleLinkedList {
  private:
    Node *head, *tail;

  public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addToHead(int value) {
        Node *node = new Node(value);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            head->previous = node;
            node->next = head;
            head = node;
        }
    }

    void addToTail(int value) {
        Node *node = new Node(value);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->previous = tail;
            tail = node;
        }
    }

    void removeFromHead() {
        head = head->next;
        head->previous = NULL;
    }

    void removeFromTail() {
        tail = tail->previous;
        tail->next = NULL;
    }

    void reverse() {
        Node *temp = NULL;
        Node *current = head;

        while (current != NULL) {
            temp = current->previous;
            current->previous = current->next;
            current->next = temp;
            current = current->previous;
        }

        temp = head;
        head = tail;
        tail = temp;
        delete current;
    }

    void print() {
        cout << "Print current list:";
        Node *current = head;

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
};