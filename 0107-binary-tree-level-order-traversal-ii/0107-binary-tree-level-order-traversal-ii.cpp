/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
        vector<vector < int>> levelOrderBottom(TreeNode *root)
        {
            vector<vector < int>> ans;
            if (root == nullptr)
            {
                return ans;
            }
            queue<TreeNode*> q;
            q.push(root);
            q.push(nullptr);
            vector<int> current;
            while (!q.empty())
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp == nullptr)
                {
                    ans.push_back(current);
                    current.clear();
                    if (!q.empty())
                    {
                        q.push(nullptr);
                    }
                }
                else
                {
                    current.push_back(temp->val);

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }

                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};