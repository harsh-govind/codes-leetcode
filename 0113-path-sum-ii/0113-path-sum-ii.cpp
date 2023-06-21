/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(vector<int> &current, vector<vector< int>> &ans, TreeNode *root, int k)
        {
            if (root == nullptr)
            {
                return;
            }

            current.push_back(root->val);

            solve(current, ans, root->left, k);
            solve(current, ans, root->right, k);
            
            if (!root->left and !root->right)
            {
                int sum = 0;
                for (int i = 0; i < current.size(); i++)
                {
                    sum += current[i];
                }

                if (sum == k)
                {
                    ans.push_back(current);
                }
            }

            current.pop_back();
        }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> current;
        vector<vector < int>> ans;
        solve(current, ans, root, targetSum);
        return ans;
    }
};