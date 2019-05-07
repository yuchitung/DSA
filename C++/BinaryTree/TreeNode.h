class TreeNode {
  public:
    int value;
    TreeNode *parent = NULL;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode() {}
    TreeNode(int value) { this->value = value; }
};