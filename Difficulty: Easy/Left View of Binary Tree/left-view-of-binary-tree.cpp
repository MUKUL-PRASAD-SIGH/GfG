class Solution {
  public:
    vector<int> leftView(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                Node* node = q.front();
                q.pop();

                // First node of this level
                if (i == 0)
                    ans.push_back(node->data);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }
        }

        return ans;
    }
};