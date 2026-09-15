class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {

        // Both are NULL
        if (r1 == NULL && r2 == NULL)
            return true;

        // One is NULL, other isn't
        if (r1 == NULL || r2 == NULL)
            return false;

        // Data doesn't match
        if (r1->data != r2->data)
            return false;

        // Check left and right subtrees
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};