class Solution {
  public:

    int checkHeight(Node* root) {

        if (root == NULL)
            return 0;

        int leftHeight = checkHeight(root->left);

        if (leftHeight == -1)
            return -1;

        int rightHeight = checkHeight(root->right);

        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(Node* root) {

        return checkHeight(root) != -1;
    }
};