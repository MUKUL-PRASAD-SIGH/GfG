class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {

                Node* node = q.front();
                q.pop();

                int index;

                if (leftToRight)
                    index = i;
                else
                    index = size - 1 - i;

                level[index] = node->data;

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            // Add current level to answer
            for (int x : level)
                ans.push_back(x);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};