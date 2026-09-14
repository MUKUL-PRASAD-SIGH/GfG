class Solution {
  public:

    void helper(Node* root, vector<int>& arr, vector<vector<int>>& ans) {

        if (root == NULL)
            return;

        arr.push_back(root->data);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(arr);
        }
        else {
            helper(root->left, arr, ans);
            helper(root->right, arr, ans);
        }

        arr.pop_back();
    }

    vector<vector<int>> paths(Node* root) {

        vector<vector<int>> ans;
        vector<int> arr;

        if (root == NULL)
            return ans;

        helper(root, arr, ans);

        return ans;
    }
};