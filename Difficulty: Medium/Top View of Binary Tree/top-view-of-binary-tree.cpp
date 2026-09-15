class Solution {
  public:
    vector<int> topView(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        // horizontal distance -> node value
        map<int, int> mp;

        // node + horizontal distance
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // First node at this horizontal distance
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if (node->left != NULL)
                q.push({node->left, hd - 1});

            if (node->right != NULL)
                q.push({node->right, hd + 1});
        }

        // map automatically gives HD from smallest to largest
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};