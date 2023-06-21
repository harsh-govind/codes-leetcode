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
        void solve(TreeNode *root, int k, vector<int> &paths, int &ans)
        {
            if (!root)
            {
                return;
            }

            paths.push_back(root->val);

            solve(root->left, k, paths, ans);
            solve(root->right, k, paths, ans);

            long long sum = 0;
            for (int i = paths.size() - 1; i >= 0; i--)
            {
                sum += paths[i];
                if (sum == k)
                {
                    ans++;
                }
            }

            paths.pop_back();
        }
    int pathSum(TreeNode *root, int targetSum)
    {
        vector<int> paths;
        int ans = 0;
        solve(root, targetSum, paths, ans);
        return ans;
    }
};