#include <iostream>
#include "Node.h"

using namespace std;

class Stack
{
  private:
    int size = 0;
    Node *top;

  public:
    Stack()
    {
        top = NULL;
    }

    int push(int value)
    {
        Node *node = new Node(value);
        if (top == NULL)
        {
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }

        size++;
    }

    void pop()
    {
        if (top != NULL)
        {

            top = top->next;

            size--;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
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

    int peakTop()
    {
        return top->value;
    }
};
