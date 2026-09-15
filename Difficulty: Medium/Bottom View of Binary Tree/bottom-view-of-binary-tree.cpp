class Solution {
  public:
    vector<int> bottomView(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mp;

        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Always update for bottom view
            mp[hd] = node->data;

            if (node->left != NULL)
                q.push({node->left, hd - 1});

            if (node->right != NULL)
                q.push({node->right, hd + 1});
        }

        // map gives horizontal distances from left to right
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};