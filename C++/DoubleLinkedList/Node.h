class Node
{
  public:
    int value;
    Node *next = NULL;
    Node *previous = NULL;

    Node(int value)
    {
        this->value = value;
    }
};