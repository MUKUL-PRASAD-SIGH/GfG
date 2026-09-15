class Solution {
  public:

    bool check(Node* left, Node* right) {

        // Both are NULL
        if (left == NULL && right == NULL)
            return true;

        // One is NULL, other isn't
        if (left == NULL || right == NULL)
            return false;

        // Values must match
        if (left->data != right->data)
            return false;

        // Mirror comparison
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(Node* root) {

        if (root == NULL)
            return true;

        return check(root->left, root->right);
    }
};