/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<double> averageOfLevels(TreeNode *root)
        {
            vector<double> ans;
            if (root == nullptr)
            {
                return ans;
            }
            double sum = 0, n = 0;
            queue<TreeNode*> q;
            q.push(root);
            q.push(nullptr);

            while (!q.empty())
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp == nullptr)
                {
                    ans.push_back(sum / n);
                    sum = 0;
                    n = 0;
                    
                    if(!q.empty())
                    {
                        q.push(nullptr);
                    }
                }
                else
                {
                    n++;
                    sum += temp->val;

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
            return ans;
        }
};