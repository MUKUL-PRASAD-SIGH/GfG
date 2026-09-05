class Solution {
  public:

    int maxPath(Node* root, int& ans) {

        if (root == NULL)
            return 0;

        int left = maxPath(root->left, ans);
        int right = maxPath(root->right, ans);

        // If a subtree gives negative contribution,
        // don't take it.
        left = max(0, left);
        right = max(0, right);

        // Path passing through current node
        ans = max(ans, left + right + root->data);

        // Return only ONE side to parent
        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {

        int ans = INT_MIN;

        maxPath(root, ans);

        return ans;
    }
};