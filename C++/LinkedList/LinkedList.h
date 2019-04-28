#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
  private:
    int size = 0;
    Node *head, *tail;

  public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addToHead(int value)
    {
        Node *node = new Node(value);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }

        size++;
    }

    int addToTail(int value)
    {
        Node *node = new Node(value);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }

        size++;
    }

    void removeFromHead()
    {
        if (head != NULL)
        {
            int value = head->value;
            head = head->next;
            size--;
        }
    }

    void removeFromTail()
    {
        if (tail != NULL)
        {
            int value = tail->value;
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            current->next = NULL;
            tail = current;
            size--;
        }
    }

    void reverse()
    {
        Node *previous = NULL;
        Node *current = head;
        Node *preceding = current->next;

        while (preceding != NULL)
        {
            current->next = previous;
            previous = current;
            current = preceding;
            preceding = preceding->next;
        }

        current->next = previous;
        tail = head;
        head = current;
    }

    void print()
    {
        cout << "Print current list:";
        Node *current = head;

        if (head == NULL)
        {
            return;
        }

        if (head == tail)
        {
            cout << head->value;
            cout << "\n";
            return;
        }

        while (current != NULL)
        {
            if (current != tail)
            {
                cout << current->value << "->";
            }
            else
            {
                cout << current->value;
            }
            current = current->next;
        }
        cout << "\n";
        delete current;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return size;
    }
};
