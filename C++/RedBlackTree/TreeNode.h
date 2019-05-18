class TreeNode {
  public:
    int data;
    bool color;
    TreeNode *left, *right, *parent;

    TreeNode(){};
    TreeNode(int data) {
        this->data = data;
    }
};