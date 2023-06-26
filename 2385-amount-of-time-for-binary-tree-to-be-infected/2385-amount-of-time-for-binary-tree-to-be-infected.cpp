/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        /*
        Three steps solution:
        - find the initial node from where infection start
        - find the node to parent mapping since we dont have node to parent mapping in tree
        - find time to be infected
        */

       	//step 1 and 2 together
        TreeNode* n2p(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &m, int start)
        {
            queue<TreeNode*> q;
            q.push(root);
            m[root] = nullptr;
            TreeNode *res = nullptr;
            while (!q.empty())
            {
                TreeNode *front = q.front();
                q.pop();

                if (front->val == start)
                {
                    res = front;
                }

                if (front->right)
                {
                    m[front->right] = front;
                    q.push(front->right);
                }

                if (front->left)
                {
                    m[front->left] = front;
                    q.push(front->left);
                }
            }
            return res;
        }

    int amountOfTime(TreeNode *root, int start)
    {
        int ans = 0;
        unordered_map<TreeNode*, TreeNode*> m;
        unordered_map<TreeNode*, bool> visited;
        TreeNode *node = n2p(root, m, start);

        queue<TreeNode*> q;

        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int n = q.size();
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                if (front->left and!visited[front->left])
                {
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if (front->right and!visited[front->right])
                {
                    flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if (m[front] and!visited[m[front]])
                {
                    flag = true;
                    visited[m[front]] = true;
                    q.push(m[front]);
                }
            }
            if (flag)
            {
                ans++;
            }
        }

        return ans;
    }
};